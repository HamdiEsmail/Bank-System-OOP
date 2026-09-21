#pragma once
#include "clsScreen.h"
#include"clsUser.h"
#include<iomanip>
class clsRegisterLoginScreen :
	protected clsScreen
{
private:
	static void _PrintRegisterLoginInfo(const clsUser::stRegisterLogin& CurrRegister) {
		cout << setw(20) << left << "" << "| " << setw(20) << left << CurrRegister.DataTime;
		cout << "| " << setw(15) << left << CurrRegister.UserName;
		cout << "| " << setw(15) << left << CurrRegister.Password;
		cout << "| " << setw(15) << left << CurrRegister.Permission << "\n";


	}
public:
	static void ShowRegisterLoginScreen() {

		
		if (!CheckAccessRight(clsUser::pShowLoginRegister)) {
			return;
		}

		vector<clsUser::stRegisterLogin>vAllRegisterLogin = clsUser::GetAllRegisterLogin();
		string Title = "Login Register Screen";
		string SubTitle = "(" + to_string(vAllRegisterLogin.size()) + ") Record(s)";

		DrawHeaderScreen(Title, SubTitle);
		cout << setw(20) << left << "" << "=========================================================================\n";
		cout << setw(20) << left << "" << "| " << setw(20) << left << "Date/Time";
		cout << "| " << setw(15) << left << "User Name";
		cout << "| " << setw(15) << left << "Password";
		cout << "| " << setw(15) << left << "Permissions";
		cout << endl << setw(20) << left << "" << "=========================================================================\n";

		for (const clsUser::stRegisterLogin& CurrReg : vAllRegisterLogin) {

			_PrintRegisterLoginInfo(CurrReg);


		}


	}


};

