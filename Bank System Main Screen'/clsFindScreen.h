#pragma once
#include"clsScreen.h"	
#include"../../clsBankClient.h"	
#include"../../clsInputValidate.h"
class clsFindScreen:protected clsScreen 
{
private :
	static void _PrintClient(clsBankClient & Client) {
		cout << "Client Info : \n";
		cout << "___________________________________________________\n";
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
	static	void ShowFindScreen() {
		if (!CheckAccessRight(clsUser::enPermission::pFindClient)) {
			return;
		}

		DrawHeaderScreen("Find Screen ");
		

		string accountNumber;
		cout << "Enter Account Number \n";
		accountNumber = clsInputValidate<string>::ReadString();
		while (!clsBankClient::isExist(accountNumber)) {
			cout << "Client Not Found !! \n";
			cout << "Enter Account Number \n";
			accountNumber = clsInputValidate<string>::ReadString();
		
		}
		clsBankClient CurrClient = clsBankClient::Find(accountNumber);
		if (CurrClient.isEmpty()) {
		
			cout << "  Client Not Found :( !!";
		
		}
		else {
			cout << "  Client Found (:\n";


		
		}
		_PrintClient(CurrClient);



	
	}
};

