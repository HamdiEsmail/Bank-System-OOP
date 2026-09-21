#pragma once
#include"clsScreen.h"
#include"../../clsInputValidate.h"
#include"clsClientListScreen.h"	
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateScreen.h"	
#include"clsFindScreen.h"
#include"clsTransactionScreen.h"
#include"clsManageUserScreen.h"
#include"Global.h"
#include"clsRegisterLoginScreen.h"
#include"clsCurrencyExchangeScreen.h"
class clsMainManue :protected clsScreen
{
private:
	static void _ShowClientList() {

		clsClientListScreen::ShowClientList();

	}
	static void _AddNewClient() {

		clsAddNewClientScreen::AddNewClient();

	}
	static	void _DeleteClient() {
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}
	static	void _UpdateClient() {
		clsUpdateClientScreen::ShowUpdateScreen();

	}
	static void _FindClient() {

		clsFindScreen::ShowFindScreen();

	}
	static void _Transaction() {

		clsTransactionScreen::ShowTransactionMenu();

	}
	static	void _ManageUser() {
		clsManageUserScreen::ShowManageUserScreen();

	}
	static	void _LogOut() {
		CurrUser = clsUser::Find("", "");

	}
	static	void _RegisterLogin() {
		clsRegisterLoginScreen::ShowRegisterLoginScreen();

	}
	static	void _GoBackToMainScreen() {
		cout << "Press Any Key To Go Back To Main Manue ";
		system("pause >0");
		ShowMainScreen();

	}
	static	void _ClearScreen() {

		system("cls");

	}
	static void _CurrencyExchange() {
		clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
	
	}
	enum enMainManueOption {
		enShowClientList = 1, enAddNewClient = 2, enDeleteClient = 3, enUpdateClient = 4, enFindClient = 5, enTransaction = 6, enManageUser = 7
		, enRegisterLoginScreen = 8, CurrencyExchange=9,enLogOut = 10
	};
	static  short _ReadOption(string text) {
		cout << text;
		short number = clsInputValidate<short>::ReadNumberBetween(1, 10);
		return number;
	}
	static void _PerformMainManueOption(enMainManueOption userChoice) {
		if (userChoice > 9 || userChoice < 1)return;
		switch (userChoice) {
		case enMainManueOption::enShowClientList:
			_ClearScreen();
			_ShowClientList();
			_GoBackToMainScreen();
			// i konw i don't need this break 
			break;
		case enMainManueOption::enAddNewClient:
			_ClearScreen();
			_AddNewClient();
			_GoBackToMainScreen();
			break;

		case enMainManueOption::enDeleteClient:
			_ClearScreen();
			_DeleteClient();
			_GoBackToMainScreen();
			break;
		case enMainManueOption::enUpdateClient:
			_ClearScreen();
			_UpdateClient();
			_GoBackToMainScreen();
			break;
		case enMainManueOption::enFindClient:
			_ClearScreen();
			_FindClient();
			_GoBackToMainScreen();
			break;
		case enMainManueOption::enTransaction:
			_ClearScreen();
			_Transaction();
			_GoBackToMainScreen();
			break;
		case enMainManueOption::enManageUser:
			_ClearScreen();
			_ManageUser();
			_GoBackToMainScreen();
			break;
		case enMainManueOption::enLogOut:
			_ClearScreen();
			_LogOut();
			break;
		case enMainManueOption::enRegisterLoginScreen:
			_ClearScreen();
			_RegisterLogin();
			_GoBackToMainScreen();

			break;
		case enMainManueOption::CurrencyExchange:
			_ClearScreen();
			_CurrencyExchange();
			_GoBackToMainScreen();
			break;


		}


	}

public:
	static	void ShowMainScreen() {
		_ClearScreen();
		DrawHeaderScreen("MainManue");


		cout << "\n\t\t\t\t_________________________________________\n";
		cout << "\t\t\t\t\t\tMain Manue Screen";
		cout << "\n\t\t\t\t_________________________________________\n";

		cout << "\t\t\t\t[1] Show Clients List \n";
		cout << "\t\t\t\t[2] Add New Client \n";
		cout << "\t\t\t\t[3] Delete Client \n";
		cout << "\t\t\t\t[4] Update Client \n";
		cout << "\t\t\t\t[5] Find Client \n";
		cout << "\t\t\t\t[6] Transaction \n";
		cout << "\t\t\t\t[7] Manage User \n";
		cout << "\t\t\t\t[8] Register Login \n";
		cout << "\t\t\t\t[9] Currency Exchange \n";
		cout << "\t\t\t\t[10] Log out \n";
		_PerformMainManueOption((enMainManueOption)_ReadOption("\t\t\t\tEntear Number Between [1-10] : "));



	}


};

