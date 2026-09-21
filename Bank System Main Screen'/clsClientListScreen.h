#pragma once
#include"clsScreen.h"
#include<iomanip>
#include"../../clsBankClient.h"
#include<iostream>
using namespace std;
class clsClientListScreen:protected clsScreen 
{
private :
static	void _PrintClientRecord(clsBankClient & client) {
	
	cout << setw(8) << ""
		<< "| " << left << setw(20) << client.getFullName()
		<< "| " << left << setw(15) << client.getAccNumber()
			<< "| " << left << setw(12) << client.Phone
			<< "| " << left << setw(20) << client.Email
			<< "| " << left << setw(10) << client.PinCode
			<< "| " << left << setw(12) << client.AccountBalance << endl;
	
	}

public:
	
static	void ShowClientList() {
	if (!CheckAccessRight(clsUser::enPermission::pShowClientList)) {
	// case I need to kick him out my Method
		return;
	}



	vector<clsBankClient>vAllClient = clsBankClient::getAllClients();
	string Title = "Client List Screen ";
	string SubTitle = "(" + to_string(vAllClient.size()) + ") Cllient(s) ";
	DrawHeaderScreen(Title,SubTitle);
	
		cout << setw(8) << ""
			<< "| " << left << setw(20) << "Client Name"
			<< "| " << left << setw(15) << "Account Number"
			<< "| " << left << setw(12) << "Phone "
			<< "| " << left << setw(20) << "Email"
			<< "| " << left << setw(10) << "PinCode"
			<< "| " << left << setw(12) << "Account Balance" << endl;
		cout << setw(8)<<"" << "________________________________________________________________________________________\n";
		for (clsBankClient &c :vAllClient) {
		
			_PrintClientRecord(c);
		}
	
	}




};

