#pragma once
#include"clsScreen.h"
#include"../../clsInputValidate.h"
#include<iomanip>
#include"clsUsersListScreen.h"
#include"AddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"	
#include"clsFindUserScreen.h"
class clsManageUserScreen :protected clsScreen
{
private:
	enum _enManageUserMenuOption {
		ListUser=1,
		AddNewUser,
		DeleteUser,
		UpdateUser,
		FindUser,
		MainMenu

	};
	static short _ReadUserChoice() {
		cout << "Please enter Number [1-6] : ";
		short userChoice = clsInputValidate<short>::ReadNumberBetween(1,6);
		return userChoice;
	}
	static void _ListUser() {
		clsUsersListScreen::ShowUserListScreen();
	
	
	}
	static void _AddNewUser() {
		AddNewUserScreen::ShowAddNewUserScreen();
	
	}
	static void _DeleteUser() {
		clsDeleteUserScreen::ShowDeleteScreen();
	
	}
	static void _UpdateUser() {
		clsUpdateUserScreen::ShowUpdateUserScreen();
	
	}
	static void _FindUser() {
		clsFindUserScreen::ShowFindUserScreen();
	
	}
	static void _GoBackToManageUser() {
		cout << "\nPress Any Key To Go Back To Manage User .....\n";
		system("pause>0");
		ShowManageUserScreen();
	}
	static void _PerformManageUserMenuOption(const _enManageUserMenuOption &UserOption) {
		system("cls");
		switch (UserOption) {
			case _enManageUserMenuOption::AddNewUser:
				_AddNewUser();
				_GoBackToManageUser();
				break;
			case _enManageUserMenuOption::ListUser:
				_ListUser();
				_GoBackToManageUser();
				break;
			case _enManageUserMenuOption::DeleteUser:
				_DeleteUser();
				_GoBackToManageUser();
				break;
			case _enManageUserMenuOption::UpdateUser:
				_UpdateUser();
				_GoBackToManageUser();
				break;
			case _enManageUserMenuOption::FindUser:
					_FindUser();
					_GoBackToManageUser();
					break;
			case _enManageUserMenuOption::MainMenu:
			break	;
			
//i leave it case when this end compile will go to Main Manue  in other switch









		}
	
	}


public:
	static void ShowManageUserScreen() {
		system("cls");
		if (!CheckAccessRight(clsUser::enPermission::pManageUser)) {
			return;
		}

		DrawHeaderScreen("Manage User Screen");
		

		cout << endl << setw(30) << "" << "_______________________________________________________\n";
		cout << setw(48) << "" << "Manage User Menu";
		cout << endl << setw(30) << "" << "_______________________________________________________\n";
		cout << setw(30) << "" << "[1] List User\n";
		cout << setw(30) << "" << "[2] Add New User\n";
		cout << setw(30) << "" << "[3] Delete User\n";
		cout << setw(30) << "" << "[4] Update User\n";
		cout << setw(30) << "" << "[5] Find User\n";
		cout << setw(30) << "" << "[6] Main Menu\n";
		cout << setw(30) << "";
		_PerformManageUserMenuOption((_enManageUserMenuOption)_ReadUserChoice());


		
	
	
	}



};

