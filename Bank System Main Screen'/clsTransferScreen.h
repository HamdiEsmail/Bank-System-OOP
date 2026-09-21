#pragma once
#include "clsScreen.h"
#include"../../clsBankClient.h"
#include"../../clsInputValidate.h"
class clsTransferScreen :
	protected clsScreen
{
private:
	static void _PrintClientCard(clsBankClient& CurrentClient) {
		cout << "Client Info :\n";
		cout << "____________________________________________\n";
		cout << "Client Name    : " << CurrentClient.getFullName() << endl;
		cout << "Account Number : " << CurrentClient.getAccNumber() << endl;
		cout << "Account Balance : " << CurrentClient.AccountBalance << endl;
		cout << "____________________________________________\n";

	}
	static string _ReadAccNumber(string Text) {
		string AccountNumber;
		cout << Text;
		AccountNumber = clsInputValidate<string>::ReadString();
		while (!clsBankClient::isExist(AccountNumber)) {
			cout << "Account Number is Not Exist !!\n";
			cout << Text;
			AccountNumber = clsInputValidate<string>::ReadString();
		
		}
		return AccountNumber;
	
	}
	static int ReadAmount(clsBankClient &SourceClient) {
		cout << "Enter Amount you want to transfer : ";
		int Amount=clsInputValidate<int>::ReadNumberBetween(0,SourceClient.AccountBalance,"Number exceeds the balance !!\nEnter Amount you want Transfer");
		return Amount;
	}

public:
	static void showTransferScreen() {

		DrawHeaderScreen("Transfer Screen");
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccNumber("Enter Account Number you want transfer From : "));
		_PrintClientCard(SourceClient);
		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccNumber("Enter Account Number you want transfer To : "));
		_PrintClientCard(DestinationClient);

		int Amount = ReadAmount(SourceClient);

		cout << "Are you sure you want to perform this operation ? [y/n] : ";
		char UserChoice;
		cin >> UserChoice;
		if (tolower(UserChoice)=='y') {
			if (SourceClient.Transfer(Amount, DestinationClient,CurrUser)) {
			
			
			cout << "Transfer Done Successfully :-)\n";
			_PrintClientCard(SourceClient);
			_PrintClientCard(DestinationClient);
		
			}
		}
		else {
		
			cout << "Transfer cancelled.\n";
		}
		





	}


};

