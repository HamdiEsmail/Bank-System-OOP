#pragma once
#include"clsScreen.h"
#include"../../clsBankClient.h"
#include"../../clsInputValidate.h"
class clsDeleteClientScreen:protected clsScreen
{
private :
static	void _PrintClient(clsBankClient &Client ) {
	
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
public:
	static void ShowDeleteClientScreen() {
		if (!CheckAccessRight(clsUser::enPermission::pDeleteClient)) {
		
			return;
		}



		DrawHeaderScreen("Delete Clinet Screen");
		

		string AccNumber;
		cout << "Enter Account Number : ";
		AccNumber = clsInputValidate<string>::ReadString();
		while (!clsBankClient::isExist(AccNumber)) {
			cout << "Account Number Is Not Exist \n";
			cout << "Enter Account Number : ";
			AccNumber = clsInputValidate<string>::ReadString();
		
		}
		clsBankClient CurrClient = clsBankClient::Find(AccNumber);
		_PrintClient(CurrClient);
		cout << "Are You Sure To Delete This Client [y/n] : ";
		char userChoice='n';
		cin >> userChoice;
		if (tolower(userChoice) == 'y') {
		
			if (CurrClient.Delete()) {

				cout << "Account Deleted Successed (: \n";
				_PrintClient(CurrClient);
			}
			else {

				cout << "Error Account was Not Deleted ): \n";
			}
		
		
		}
	
	
	
	}

};

