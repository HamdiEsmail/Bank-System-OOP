#pragma once
#include "clsScreen.h"
#include"clsCurrency.h"
#include"../../clsInputValidate.h"
class clsCurrencyCalculatorScreen :
	protected clsScreen
{
private:
	static void _PrintCurrencyData(clsCurrency& Curr, string text) {
		cout << text << "\n";
		cout << "___________________________________\n";
		cout << "Country : " << Curr.GetCountry() << endl;
		cout << "Code    : " << Curr.GetCurrencyCode() << endl;
		cout << "Name    : " << Curr.GetCurrencyName() << endl;
		cout << "Rate($) : " << Curr.GetRate() << endl;
		cout << "___________________________________\n";


	}
	static clsCurrency _GetCurrencyObj(string text) {
		string Code;
		cout << text;
		Code = clsInputValidate<string>::ReadString();
		while (!clsCurrency::IsCurrencyExist(Code)) {
			cout << "Currency Code is not exist !!!\n";
			cout << text;
			Code = clsInputValidate<string>::ReadString();

		}
		clsCurrency C = clsCurrency::FindByCode(Code);
		return C;
	}
	static float _ReadAmount() {
		cout << "Enter your Amount : ";
		float Amount = (float)clsInputValidate<float>::ReadNumber();
		return Amount;
	}
	static void _PrintCalculationResult(float Amount, clsCurrency& CurrencyFrom, clsCurrency& CurrencyTo) {
		_PrintCurrencyData(CurrencyFrom, "Currency From");
		float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);
		cout << "Amount From " << CurrencyFrom.GetCurrencyCode() << " To USD = " << AmountInUSD << endl;
		if (CurrencyTo.GetCurrencyCode() == "USD") return; 
		float AmountAfterCalc = CurrencyFrom.ConvertToOtherCurrency(Amount,CurrencyTo);
		cout << "Converting To \n";
		_PrintCurrencyData(CurrencyTo,"Currency To");
		cout << "Amount From " << CurrencyFrom.GetCurrencyCode() << " To  " << CurrencyTo.GetCurrencyCode()<<Amount<<" = " << AmountAfterCalc << endl;

	}
public:
	static void ShowCurrencyCalculatorScreen() {

		DrawHeaderScreen("Calculator Screen");

		bool UserChoice = true;
		while (UserChoice) {
			system("cls");
			clsCurrency CurrencyFrom = _GetCurrencyObj("Enter Currency From : ");
			clsCurrency CurrencyTo= _GetCurrencyObj("Enter Currency To : ");
			float Amount = _ReadAmount();
			_PrintCalculationResult(Amount,CurrencyFrom,CurrencyTo);
			cout << "Do you want to perfrom another calculation ? [y/n] : ";
			char MoreCalc = 'n';
			cin >> MoreCalc;
			if (tolower(MoreCalc) == 'y') {

				UserChoice = true;

			}
			else {
				UserChoice = false;
			}



		}

	}

};

