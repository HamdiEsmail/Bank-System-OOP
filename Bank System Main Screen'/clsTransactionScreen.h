#pragma once
#include"clsScreen.h"
#include"../../clsInputValidate.h"
#include<iomanip>
#include"clsDeposit.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalanceScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
class clsTransactionScreen :protected clsScreen
{
private:
	enum _enTransactionChoice {
		Deposit = 1,
		Withdraw = 2,
		TotalBalance = 3,
		Transfer = 4,
		TransferLog =5,
		MainMenu = 6

	};
	static short _ReadTransactionChoice() {
		cout << setw(30) << "" << "Please Take A Number [1-6] : ";
		short UserChoice = clsInputValidate<short>::ReadNumberBetween(1, 6);
		return UserChoice;

	}
	static	void _Deposit() {
		clsDepositScreen::ShowDepositScreen();

	}
	static	void _Withdraw() {
		clsWithdrawScreen::ShowWithdrawScreen();

	}
	static  void _TotalBalance() {
		clsTotalBalanceScreen::ShowBalancesScreen();

	}
	static void _Transfer() {
		clsTransferScreen::showTransferScreen();

	}
	static void _TransferLog() {
		clsTransferLogScreen::ShowTransformListScreen();

	}
	static void _GoBackToTransactionScreen() {
		cout << "Press Any Key To Go Back To Transaction Menu \n";
		system("pause>0");
		ShowTransactionMenu();

	}
	static void _PerformTransactionChoice(_enTransactionChoice UserChoice) {
		system("cls");
		switch (UserChoice)
		{

		case _enTransactionChoice::Deposit:
			_Deposit();
			_GoBackToTransactionScreen();
			break;
		case _enTransactionChoice::Withdraw:
			_Withdraw();
			_GoBackToTransactionScreen();
			break;
		case _enTransactionChoice::TotalBalance:
			_TotalBalance();
			_GoBackToTransactionScreen();
			break;
		case _enTransactionChoice::Transfer:
			_Transfer();
			_GoBackToTransactionScreen();
			break;
		case _enTransactionChoice::TransferLog:
			_TransferLog();
			_GoBackToTransactionScreen();
			break;
		case _enTransactionChoice::MainMenu:

			// here will end the program and will go back to main manue
			;


		}



	}


public:
	static void ShowTransactionMenu() {
		system("cls");
		if (!CheckAccessRight(clsUser::enPermission::pTrancaction)) {
			return;
		}

		DrawHeaderScreen("Transaction Menu");


		cout << setw(20) << " " << "____________________________________________________________________\n";
		cout << setw(30) << " " << "\t\tTransaction Main Menu \n";
		cout << setw(20) << " " << "____________________________________________________________________\n";
		cout << setw(30) << " " << "[1] Deposit\n";
		cout << setw(30) << " " << "[2] Withdraw\n";
		cout << setw(30) << " " << "[3] Total Balance\n";
		cout << setw(30) << " " << "[4] Transfer\n";
		cout << setw(30) << " " << "[5] Transfer Log \n";
		cout << setw(30) << " " << "[6] Main Menu\n";
		_PerformTransactionChoice((_enTransactionChoice)_ReadTransactionChoice());

	}
};

