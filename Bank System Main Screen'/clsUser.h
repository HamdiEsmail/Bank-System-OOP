#pragma once
#include"../../clsPerson.h"
#include"../../clsString.h"
#include"../../clsDate.h"
#include"../../clsUtil.h"
#include<vector>
#include<string>
#include<fstream>




class clsUser :public clsPerson
{
public:
	 struct stRegisterLogin;

private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddMode = 2 };
	enMode _Mode;
	string _UserName;
	string _Password;
	int    _Permission;
	bool _MarkForDelete = false;
	static string  _ConvertUserToLine(clsUser& User, string Seperator = "#//#") {
		string UserRecord = "";
		UserRecord += User.FirstName + Seperator;
		UserRecord += User.LastName + Seperator;
		UserRecord += User.Email + Seperator;
		UserRecord += User.Phone + Seperator;
		UserRecord += User.UserName + Seperator;
		UserRecord +=clsUtil::EncryptText(User.Password) + Seperator;
		UserRecord += to_string(User.Permission);

		return UserRecord;

	}
	static clsUser _ConvertLineToObjectUser(string line) {
		vector<string> vUserData = clsString::Split(line);
		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5]), stoi(vUserData[6]));

	}
	static vector<clsUser> _LoadUsersDataFromFile(string FileName = "Users.txt") {
		fstream myFile;
		vector<clsUser>vAllUser;
		myFile.open(FileName, ios::in);
		if (myFile.is_open()) {
			string line;

			while (getline(myFile, line)) {
				if (line != "") {
					clsUser currUser = _ConvertLineToObjectUser(line);
				
					vAllUser.push_back(currUser);
				}


			}

			myFile.close();

		}
		return vAllUser;

	}
	static void _SaveUserDataToFile(vector<clsUser>& vAllUser, string FileName = "Users.txt") {
		fstream	MyFile;
		MyFile.open(FileName, ios::out);
		if (MyFile.is_open()) {
			string Line;
			for (clsUser& currUser : vAllUser) {
				if (!currUser._MarkForDelete) {
					Line = _ConvertUserToLine(currUser);
					MyFile << Line << endl;

				}

			}

			MyFile.close();
		}





	}
	static clsUser _GetEmptyUser() {
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	void _AddDataLineToFile(string Line) {
		fstream myFile;
		myFile.open("Users.txt", ios::app | ios::out);
		if (myFile.is_open()) {
			myFile << Line << endl;

			myFile.close();
		}


	}
	void _AddNewUser() {
		_AddDataLineToFile(_ConvertUserToLine(*this));
	}
	void _Update() {
		vector<clsUser>vAllUsers = _LoadUsersDataFromFile();
		for (clsUser& CurrUser : vAllUsers) {
			if (CurrUser.UserName == _UserName) {
				CurrUser = *this;
				break;
			}

		}
		_SaveUserDataToFile(vAllUsers);


	}
	string _PrepareLogin(string Delim = "#//#") {
		string Line = clsDate::GetCurrDateString() + Delim + _UserName + Delim + _Password + Delim + to_string(_Permission);
		return Line;
	}
	static stRegisterLogin ConvertLineToStRegisterLogin(string currLine) {
		vector<string>Temp = clsString::Split(currLine);
		stRegisterLogin RegisterLogin;
		RegisterLogin.DataTime = Temp[0];
		RegisterLogin.UserName = Temp[1];
		RegisterLogin.Password =Temp[2];
		RegisterLogin.Permission = stoi(Temp[3]);
		return RegisterLogin;
	}

public:
	clsUser(enMode mode, string firstName, string lastName, string email, string phone, string userName, string password, int permission)
		:clsPerson(firstName, lastName, phone, email) {

		_Mode = mode;
		_UserName = userName;
		_Password = password;
		_Permission = permission;


	}
	static enum enPermission { pAll = -1, pShowClientList = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8, pFindClient = 16, pTrancaction = 32, pManageUser = 64,pShowLoginRegister=128 };
	static struct stRegisterLogin {
		string DataTime;
		string UserName;
		string Password;
		int Permission;

	};
	void SetUserName(string UserName) {

		_UserName = UserName;
	}
	string GetUserName() {
		return _UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName))string UserName;

	void SetPassword(string Password) {
		_Password = Password;
	}
	string GetPassword() {
		return _Password;
	}
	__declspec(property (get = GetPassword, put = SetPassword))string Password;

	void SetPermission(int permission) {
		_Permission = permission;
	}
	int GetPermission() {
		return _Permission;
	}
	__declspec(property(get = GetPermission, put = SetPermission)) int Permission;

	bool IsEmpty() {
		return	_Mode == enMode::EmptyMode;
	}

	static clsUser Find(string UserName, string Password = "") {
		vector<clsUser>vAllUser = _LoadUsersDataFromFile();
		for (clsUser& currUser : vAllUser) {

			if (currUser.UserName == UserName && (Password.empty() || Password == currUser.Password)) return currUser;
		}
		return _GetEmptyUser();
	}

	static bool IsExist(string UserName) {
		clsUser user = Find(UserName);
		return (!user.IsEmpty());

	}




	// but we need to access Add New so will Make An instace with addMode To Access this method
	static clsUser GetNewUserObject(string UserName) {
		return clsUser(enMode::AddMode, "", "", "", "", UserName, "", 0);
	}

	bool Delete() {
		vector<clsUser>vAllUser = _LoadUsersDataFromFile();
		for (clsUser& CurrUser : vAllUser) {
			if (CurrUser.UserName == _UserName) {
				CurrUser._MarkForDelete = true;
				break;

			}



		}
		_SaveUserDataToFile(vAllUser);
		*this = _GetEmptyUser();
		return true;
	}

	enum enSave { svFaildEmptyObject = 0, svSuccessed = 1, svFaillUserExist = 2 };
	enSave Save() {
		switch (_Mode) {
		case enMode::AddMode:
			if (IsExist(_UserName)) {
				return svFaillUserExist;

			}
			else {
				_AddNewUser();
				_Mode = enMode::UpdateMode;
				return enSave::svSuccessed;

			}


		case enMode::EmptyMode:
			return enSave::svFaildEmptyObject;

		case enMode::UpdateMode:
			_Update();
			return enSave::svSuccessed;

		default:return enSave::svFaildEmptyObject;





		}


	}

	static vector<clsUser>GetUserList() {
		return _LoadUsersDataFromFile();
	}


	bool CheckAccessPermission(enPermission Permission) {
		if (this->Permission == enPermission::pAll) return true;
		if ((this->Permission & Permission) == Permission)return true;
		return false;

	}

	void RegisterLogin() {
		string Line = _PrepareLogin();
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);
		if (MyFile.is_open()) {
			MyFile << Line << endl;
			MyFile.close();
		}

	}


	static vector<stRegisterLogin> GetAllRegisterLogin() {
		fstream MyFile;
		vector<stRegisterLogin>vAllRegisterLogin;
		stRegisterLogin	CurrRegsterLogin;
		string line;
		MyFile.open("LoginRegister.txt", ios::in);
		if (MyFile.is_open()) {
			while (getline(MyFile, line)) {
				if (line!="") {
					CurrRegsterLogin = ConvertLineToStRegisterLogin(line);
					vAllRegisterLogin.push_back(CurrRegsterLogin);
				}
			
			
			
			}



			MyFile.close();
		}
		return vAllRegisterLogin;
	}






};

