#pragma once
#include "clsScreen.h"
#include"../../clsInputValidate.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include"clsCurrencyCalculatorScreen.h"
class clsCurrencyExchangeScreen :
    protected clsScreen
{
private:
    enum enCurrencyExchangeChoice {
        ListCurrency = 1,
        FindCurrency = 2,
        UpdateRate = 3,
        CurrencyCalculator = 4,
        MainMenu = 5

    };
    static void _ListCurrencies() {

        clsCurrenciesListScreen::ShowCurreniesListScreen();
    }
    static void _FindCurrency() {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }
    static void _UpdateRate() {
        clsUpdateCurrencyScreen::ShowCurrencyUpdateScreen();

    }
    static void _CurrencyCalculator() {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }
    static void _GoBackToCurrencyMenu() {
        cout << "Press Any key to go back to Currency Menu ....\n";
        system("pause>0");
        ShowCurrencyExchangeScreen();
    
    }
    static int _ReadCurrencyChoice() {
        cout << "Choose what do you want to do [1-5] : ";
        int UserChoice = clsInputValidate<int>::ReadNumberBetween(1, 5);
        return UserChoice;
    
    
    }
    static void _PerformCurrencyMenuChoice(enCurrencyExchangeChoice Choice) {
        system("cls");
        if (Choice > 5 || Choice < 0) return;
        switch (Choice) {
        case enCurrencyExchangeChoice::ListCurrency:
            _ListCurrencies();
            _GoBackToCurrencyMenu();
            break;
        case enCurrencyExchangeChoice::FindCurrency:
            _FindCurrency();
            _GoBackToCurrencyMenu();
            break;
        case enCurrencyExchangeChoice::UpdateRate:
            _UpdateRate();
            _GoBackToCurrencyMenu();
            break;
        case enCurrencyExchangeChoice::CurrencyCalculator:
            _CurrencyCalculator();
            _GoBackToCurrencyMenu();
            break;
        case enCurrencyExchangeChoice::MainMenu:
            break;
        
        
        }
    
    }
public:
    static void ShowCurrencyExchangeScreen() {
        system("cls");
        DrawHeaderScreen("Currency Exchange Main Screen ");
        cout << "\t\t\t\t==========================================================\n";
        cout << "\t\t\t\t\t\t Main Menu \n";
        cout << "\t\t\t\t==========================================================\n";
        cout << "\t\t\t\t\t[1]List Currencies \n";
        cout << "\t\t\t\t\t[2]Find Currency \n";
        cout << "\t\t\t\t\t[3]Update Rate \n";
        cout << "\t\t\t\t\t[4]Currency Calculator \n";
        cout << "\t\t\t\t\t[5]Main Menu \n";
        cout << "\t\t\t\t==========================================================\n";
        cout << "\t\t\t\t"; _PerformCurrencyMenuChoice((enCurrencyExchangeChoice)_ReadCurrencyChoice());

    
    }


};

