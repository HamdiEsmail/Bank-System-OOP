#pragma once
#include "clsScreen.h"
#include"../../clsInputValidate.h"
#include"Global.h"
#include"clsMainManue.h"

class clsLoginScreen :
    protected clsScreen
{
private:
    static bool Login() {
       
        bool IsLoginFailed = false;
        int FaildTrial = 0;
        string UserName, Password;
        do {
            if (IsLoginFailed) {
                FaildTrial++;
                cout << "Invalid username or password.\n";
                cout << "You have " << (3 - FaildTrial) << " Trial(s)\n";
            } 

            if (FaildTrial == 3) {
                cout << "You are Locked\n";
                return false;
            }
           
       

          
            cout << "Please enter User Name : ";
            UserName = clsInputValidate<string>::ReadString();
            cout << "Please enter Password  : ";
            Password = clsInputValidate<string>::ReadString();
            CurrUser = clsUser::Find(UserName, Password);
            IsLoginFailed = CurrUser.IsEmpty();





        } while (IsLoginFailed );
        CurrUser.RegisterLogin();
        clsMainManue::ShowMainScreen();
    
    
    }
  

public:
    static bool ShowLoginScreen() {
        system("cls");
        DrawHeaderScreen(" Login Screen ");
        return Login();



    
    }


};

