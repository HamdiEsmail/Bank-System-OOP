#pragma once
#include "clsScreen.h"
#include"../../clsBankClient.h"
#include"../../clsInputValidate.h"
class clsDepositScreen :
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
public:
	static void ShowDepositScreen() {
		DrawHeaderScreen("Deposit Screen");
		string AccNumber="";
		cout << "Pleasa enter you Account Number : ";
	 AccNumber=	clsInputValidate<string>::ReadString();
	 while (!clsBankClient::isExist(AccNumber)) {
	 
		 cout << "Error !! Account Number (" << AccNumber << ") is Not Exist \n";
		 cout << "Pleasa enter you Account Number : ";
		 AccNumber = clsInputValidate<string>::ReadString();
	 
	 
	 
	 }
	 clsBankClient CurrClient = clsBankClient::Find(AccNumber);
	 _PrintClient(CurrClient);
	 cout << "Enter Your Amount To Depsit : ";
	 double DepositAmount = clsInputValidate<double>::ReadNumber();

	 char UserChoice='n';
	 cout << "Are You Sure You Want To Deposit This Amount ? ";
	 cin >> UserChoice;
	 if (tolower(UserChoice)=='y') {
		 CurrClient.Deposit(DepositAmount);
		 cout << "Deposit Successfuly (: \n";
		 cout << "New Balance Is : " << CurrClient.AccountBalance << endl;
	 
	 
	 
	 }
	
	
	}
    


};

