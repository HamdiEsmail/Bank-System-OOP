#pragma once
#include "clsScreen.h"
#include"../../clsBankClient.h"
#include"../../clsInputValidate.h"
class clsWithdrawScreen :
    protected clsScreen
{
private:
	static void _PrintClient(clsBankClient& Client) {
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
	static string _ReadAccountNumber() {
		cout << "Please enter your Account Number \n";
		string AccountNumber = clsInputValidate<string>::ReadString();
		return AccountNumber;
	
	}
public:
	static void ShowWithdrawScreen() {
		DrawHeaderScreen("Withdraw Screen");

		string AccounNumber = _ReadAccountNumber();
		while (!clsBankClient::isExist(AccounNumber)) {
			cout << "Account number Not Exist :( \n";
			AccounNumber = _ReadAccountNumber();
		}
		clsBankClient CurrClient = clsBankClient::Find(AccounNumber);
		_PrintClient(CurrClient);
		cout << "Enter an amount you need : ";
		double WithdrawAmount = clsInputValidate<double>::ReadNumber();
		while (WithdrawAmount > CurrClient.AccountBalance) {
			cout << "Amount More Then Balance !!\n";
			WithdrawAmount = clsInputValidate<double>::ReadNumber();


		}
		cout << "Are You Sure You Want To Perfrom This Withdraw [y/n] : ";

		char UserChoice = 'n';
		cin >> UserChoice;
		if (tolower(UserChoice) == 'y') {
			if (CurrClient.Withdraw(WithdrawAmount)) {
				cout << "Amount Withdraw Successffuly \n";
				cout << "New Balance is : " << CurrClient.AccountBalance << endl;
			
			
			}
			else {
				cout << "Can't Withdraw , insufficient Balance ! \n";
				cout << "Withdraw Amount is : " << WithdrawAmount << endl;
				cout << "Curr Balance :"<<CurrClient.AccountBalance;
			}

		
		}
		else {
		
			cout << "Operation was Canceld .\n";
		}




	
	}

};

