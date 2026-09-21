#pragma once
#include "clsScreen.h"
#include"../../clsBankClient.h"
#include"../../clsUtil.h"
#include<iomanip>
class clsTotalBalanceScreen :
    protected clsScreen
{
private :
  static  void _PrintClientRecord(clsBankClient &client) {
       
        cout <<setw(10)<<"" << "| " << left << setw(25) << client.getAccNumber();
        cout << setw(10)<<"" << "| " << left << setw(40) << client.getFullName();
        cout << setw(10)<<"" << "| " << left << setw(12) << client.AccountBalance << endl;
    
    
    }
public:
  static  void ShowBalancesScreen() {
        vector<clsBankClient>vAllClient = clsBankClient::getAllClients();
        double TotalBalances = clsBankClient::GetTotalBalance();
        string Title = "Balances List Screen ";
        string SubTitle = "(" + to_string(vAllClient.size())+") Client(s)";
        DrawHeaderScreen(Title,SubTitle);
       

        cout << setw(10) << "" << "____________________________________________________________________________\n";
        cout << setw(10) << "" << "| " <<left<< setw(25) << "Account Number";
        cout << setw(10) << "" << "| " << left << setw(40) << "Client Name";
        cout << setw(10) << "" << "| " << left << setw(12) << "Balance";
        cout <<endl<< setw(10) << "" << "____________________________________________________________________________\n";


        for (clsBankClient &c:vAllClient) {
            _PrintClientRecord(c);
        
        }
        cout << setw(10) << "" << "____________________________________________________________________________\n";
        cout << setw(40) << "" << "Total Balances : " << TotalBalances << endl;
        cout << setw(40) << "" << clsUtil::NumberToText(TotalBalances)<<endl;
        



    }



};

