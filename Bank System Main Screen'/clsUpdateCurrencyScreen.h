#pragma once
#include "clsScreen.h"
#include"clsCurrency.h"
#include"../../clsInputValidate.h"
class clsUpdateCurrencyScreen :
    protected clsScreen
{
private:
    static void _PrintCurrencyData(clsCurrency &Curr) {
        cout << "Currency Info : \n";
        cout << "___________________________________\n";
        cout << "Country : " << Curr.GetCountry() << endl;
        cout << "Code    : " << Curr.GetCurrencyCode() << endl;
        cout << "Name    : " << Curr.GetCurrencyName() << endl;
        cout << "Rate($) : " << Curr.GetRate()<<endl;
        cout << "___________________________________\n";

    
    }
public:
    static void ShowCurrencyUpdateScreen() {
        DrawHeaderScreen("Currency Update Screen ");
        cout << "Please enter Currency Code : ";
        string Code = clsInputValidate<string>::ReadString();
        while (!clsCurrency::IsCurrencyExist(Code)) {
            cout << "Currency Code With " << Code << " is Not Exist !!\n";
            cout << "Please enter Currency Code : ";
             Code = clsInputValidate<string>::ReadString();
        }
        clsCurrency CurrCurrency = clsCurrency::FindByCode(Code);
        _PrintCurrencyData(CurrCurrency);
        cout << "Are you sure you want to Update the rate of the currency ? [y/n] : ";
        char UserChoice;
        cin >> UserChoice;
        if (tolower(UserChoice) == 'y') {
        
            cout << "Enter New Rate : ";
            float number = clsInputValidate<float>::ReadNumber();
            CurrCurrency.UpdateRate(number);
            cout << "Currency Rate Updated Successfuly :) \n";
            _PrintCurrencyData(CurrCurrency);
        }
        else {
            cout << "Update Currency Canceled :( \n";
        
        }
       

    
    }

};

