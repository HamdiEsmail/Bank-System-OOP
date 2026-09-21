#pragma once
#include "clsScreen.h"
#include"clsCurrency.h"
#include"../../clsInputValidate.h"  
class clsFindCurrencyScreen :
	protected clsScreen
{
private:

	static void _PrintCurrencyData(clsCurrency &Currency) {
		cout << "Curreny Info : \n";
		cout << "______________________________\n";
		cout << "Country :" << Currency.GetCountry() << endl;
		cout << "Code    :" << Currency.GetCurrencyCode() << endl;
		cout << "Name    :" << Currency.GetCurrencyName() << endl;
		cout << "Rate    :" << Currency.GetRate() << endl;

	}
	static void _ShowResult(clsCurrency &C) {
		if (C.IsEmpty()) {
			cout << "Currency Not Found :( !! \n";
		
		}
		else {
			cout << "Currency Found :)  \n";
			_PrintCurrencyData(C);
		
		
		}
	
	}
public:
	static void ShowFindCurrencyScreen() {
	
		DrawHeaderScreen("Find Currency Screen");
		cout << "Find By [1] Code ,[2] Country Name : ";
		int UserChoice = clsInputValidate<int>::ReadNumberBetween(1, 2);
		if (UserChoice==1) {
			cout << "Enter Your Code : ";
			string Code = clsInputValidate<string>::ReadString();
			clsCurrency C = clsCurrency::FindByCode(Code);
			_ShowResult(C);
		
		}
		else {
			cout << "Enter Your Country : ";
			string Country = clsInputValidate<string>::ReadString();
			clsCurrency C = clsCurrency::FindByCountry(Country);
			_ShowResult(C);

			cout << "______________________________\n";

		
		
		}
	}



};

