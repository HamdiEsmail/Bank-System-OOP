#pragma once
#include"clsScreen.h"
#include"../../clsBankClient.h"	
#include"../../clsInputValidate.h"

class clsAddNewClientScreen :protected clsScreen
{
private:

	static	void _PrintClient(clsBankClient& Client) {
		cout << "Client Info : \n";
		cout << "First Name     : " << Client.FirstName << endl;
		cout << "Last  Name     : " << Client.LastName << endl;
		cout << "Full  Name     : " << Client.getFullName() << endl;
		cout << "Phone          : " << Client.Phone << endl;
		cout << "Password       : " << Client.PinCode << endl;
		cout << "Email          : " << Client.Email << endl;
		cout << "Account Number : " << Client.getAccNumber() << endl;
		cout << "Balance        : " << Client.AccountBalance << endl;


	}
	static	void _ReadClientData(clsBankClient& Client) {
		cout << "Enter First Name   : ";
		Client.FirstName = clsInputValidate<string>::ReadString();
		cout << "Enter Last Name    : ";
		Client.LastName = clsInputValidate<string>::ReadString();
		cout << "Enter Phone Number : ";
		Client.Phone = clsInputValidate<string>::ReadString();
		cout << "Enter Password     : ";
		Client.PinCode = clsInputValidate<string>::ReadString();
		cout << "Enter Email        : ";
		Client.Email = clsInputValidate<string>::ReadString();
		cout << "Enter Balance      : ";
		Client.AccountBalance = clsInputValidate<double>::ReadNumber();
	}
public:
	static	void AddNewClient() {
		if (!CheckAccessRight(clsUser::enPermission::pAddNewClient)) {
			return;


		}
		DrawHeaderScreen("Add Client Screen");
	
		string accNumber;
		cout << "Enter Account Number : ";
		accNumber = clsInputValidate<string>::ReadString();
		while (clsBankClient::isExist(accNumber)) {
			cout << "Account Number is Exist !! \n";

			cout << "Enter Account Number \n";
			accNumber = clsInputValidate<string>::ReadString();
		}
		clsBankClient NewClient = clsBankClient::getAddNewClient(accNumber);
		_ReadClientData(NewClient);
		clsBankClient::enSave save = NewClient.Save();
		switch (save) {

		case clsBankClient::enSave::svFaillAccountNumExist:
			cout << "Client Didn't Save Because He Is Exist !! ): \n";
			break;
		case clsBankClient::enSave::svFaillEmptyObj:
			cout << "Client Didn't Save Because He Is Empty  !! ): \n";
			break;
		case clsBankClient::enSave::svSuccessed:
			cout << "Client Saved successed (: \n";
			_PrintClient(NewClient);
		}



	}

};

