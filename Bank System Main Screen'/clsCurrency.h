#pragma once
#include<string>
#include<fstream>
#include<vector>
#include"../../clsUtil.h"
#include"../../clsString.h"
using namespace std;


class clsCurrency
{
private:
	enum enMode { EmptyMode, UpdateMode };
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	static	clsCurrency _ConvertLineToCurrencyObject(string Line) {
		vector<string>vLine = clsString::Split(Line);
		return clsCurrency(enMode::UpdateMode, vLine[0], vLine[1], vLine[2], stof(vLine[3]));

	}
	string _ConvertCurrencyObjToLine(clsCurrency CurrCurrency, string Delim = "#//#") {
		string line;
		line += CurrCurrency.GetCountry() + Delim;
		line += CurrCurrency.GetCurrencyCode() + Delim;
		line += CurrCurrency.GetCurrencyName() + Delim;
		line += to_string(CurrCurrency.GetRate());
		return line;



	}
	static vector<clsCurrency> _LoadCurrencyDataFromFile() {
		vector<clsCurrency>vAllCurrencyData;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {
				clsCurrency CurrCurrencyData = _ConvertLineToCurrencyObject(line);
				vAllCurrencyData.push_back(CurrCurrencyData);
			}
			MyFile.close();
		}
		return vAllCurrencyData;

	}
	void _SaveCurrencyDataToFile(vector<clsCurrency>vAllCurrencyData) {
		string line;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);
		if (MyFile.is_open()) {
			for (clsCurrency& Curr : vAllCurrencyData) {
				line = _ConvertCurrencyObjToLine(Curr);
				MyFile << line << endl;

			}
			MyFile.close();
		}

	}
	void _Update() {
		vector<clsCurrency> vAllCurency = _LoadCurrencyDataFromFile();
		for (clsCurrency& Curr : vAllCurency) {
			if (Curr.GetCurrencyCode() == GetCurrencyCode()) {

				Curr = *this;
				break;
			}



		}
		_SaveCurrencyDataToFile(vAllCurency);

	}
	static clsCurrency _GetEmptyCurrencyObject() {

		return clsCurrency(enMode::EmptyMode, "", "", "", 0);

	}

public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;


	};

	bool IsEmpty() {
		return(_Mode == enMode::EmptyMode);
	}
	string GetCountry() {
		return _Country;
	}
	string GetCurrencyCode() {
		return _CurrencyCode;
	}
	string GetCurrencyName() {
		return _CurrencyName;
	}
	float GetRate() {
		return _Rate;
	}
	void UpdateRate(float NewRate) {
		_Rate = NewRate;
		_Update();

	}

	static clsCurrency FindByCode(string Code) {
		fstream myFile;
		myFile.open("Currencies.txt", ios::in);
		Code = clsString::toUpperCase(Code);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsCurrency Curr = _ConvertLineToCurrencyObject(line);
				if (Curr.GetCurrencyCode() == Code) {
					myFile.close();
					return Curr;
				}


			}

			myFile.close();
		}
		return _GetEmptyCurrencyObject();

	}
	static 	clsCurrency FindByCountry(string Country) {
		fstream myFile;
		myFile.open("Currencies.txt", ios::in);
		Country = clsString::toUpperCase(Country);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsCurrency Curr = _ConvertLineToCurrencyObject(line);
				if (clsString::toUpperCase(Curr.GetCountry()) == Country) {
					myFile.close();
					return Curr;
				}


			}

			myFile.close();
		}
		return _GetEmptyCurrencyObject();

	}
	static  bool IsCurrencyExist(string CurrencyCode) {
		clsCurrency Curr = FindByCode(CurrencyCode);
		return (!Curr.IsEmpty());

	}
	
	static vector<clsCurrency>GetAllCurrenciesData() {

		return _LoadCurrencyDataFromFile();
	}
	float ConvertToUSD(int Amount) {
		return ((float)Amount / GetRate());
	
	}
	float ConvertToOtherCurrency(int Amount,clsCurrency C2) {
		float AmountInUSD = ConvertToUSD(Amount);
		if (C2.GetCurrencyCode() == "USD") return AmountInUSD;
		return (float)C2.GetRate() * AmountInUSD;


	}
};

