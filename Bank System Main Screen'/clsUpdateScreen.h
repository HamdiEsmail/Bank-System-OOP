#pragma once
#include"clsScreen.h"
#include"../../clsBankClient.h"
#include"../../clsInputValidate.h"
class clsUpdateClientScreen:protected clsScreen
{
private :

		static	void _PrintClient(clsBankClient & Client) {
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
	static void ShowUpdateScreen() {
		if (!CheckAccessRight(clsUser::enPermission::pUpdateClient)) {
			return;
		}

		DrawHeaderScreen("Update Screen");
	

		string AccNumber;
		cout << "Enter Account Number : ";
		AccNumber = clsInputValidate<string>::ReadString();
		while (!clsBankClient::isExist(AccNumber)) {
			cout << "Client Is Not Exist !!\n";
			cout << "Enter Account Number : ";
			AccNumber = clsInputValidate<string>::ReadString();
		
		}
		clsBankClient CurrClient = clsBankClient::Find(AccNumber);
		_PrintClient(CurrClient);
		char userChoice = 'n';
		cout<<"Are You Sure You want To Update This Client [y/n]";
		cin >> userChoice;
		if (tolower(userChoice)=='y') {
			_ReadClientData(CurrClient);
			clsBankClient::enSave SaveResult=CurrClient.Save();
			switch (SaveResult) {
			case clsBankClient::enSave::svFaillEmptyObj:
				cout << "Error !! Client Is Empty :( ";
				break;
			case clsBankClient::enSave::svSuccessed:
				cout << "Client saved Successed (: ";
				_PrintClient(CurrClient);
				break;
			case clsBankClient::enSave::svFaillAccountNumExist:
				cout << "Error !! Client Is Exist :( ";
				break;
			default:
				cout << "Unknown Error";
				 // ;

			
			
			}
		}


	}
	


};

