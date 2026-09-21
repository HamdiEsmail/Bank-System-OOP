#pragma once
#include "clsScreen.h"
#include"clsCurrency.h"
#include<iomanip>
class clsCurrenciesListScreen :
	protected clsScreen
{
private:
	static void _PrintCurrencyData(clsCurrency CurrData) {
		cout << setw(10) << "";
		cout << "| " << setw(30) << left << CurrData.GetCountry();
		cout << "| " << setw(10) << left << CurrData.GetCurrencyCode();
		cout << "| " << setw(40) << left << CurrData.GetCurrencyName();
		cout << "| " << setw(12) << left << CurrData.GetRate() << endl;
	}
public:
	static void ShowCurreniesListScreen() {
		vector<clsCurrency>vAllCurreniesData = clsCurrency::GetAllCurrenciesData();
		string Title = "Currencies List Screen ";
		string SubTitle = "(" + to_string(vAllCurreniesData.size()) + ") Currency ";
		DrawHeaderScreen(Title, SubTitle);
		cout << setw(10) << "" << "______________________________________________________________________________________________________\n";
		cout << setw(10) << "";
		cout << "| " << setw(30) << left << "Country";
		cout << "| " << setw(10) << left << "Code";
		cout << "| " << setw(40) << left << "Name";
		cout << "| " << setw(12) << left << "Rate $" << endl;
		cout << setw(10) << "" << "______________________________________________________________________________________________________\n";
		for (clsCurrency &C:vAllCurreniesData) {
		
			_PrintCurrencyData(C);
		}


	}
};

