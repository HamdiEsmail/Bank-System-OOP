#pragma once
#include "clsScreen.h"
#include"../../clsInputValidate.h"
#include"clsUser.h"
class clsFindUserScreen :
    protected clsScreen
{
private:
    static  void _PrintUserCard(clsUser& User) {
        cout << "User Info : \n";
        cout << "_____________________________\n";
        cout << "First Name   : " << User.FirstName << endl;
        cout << "Last Name    : " << User.LastName << endl;
        cout << "Full Name    : " << User.getFullName() << endl;
        cout << "Email        : " << User.Email << endl;
        cout << "Phone        : " << User.Phone << endl;
        cout << "User Name    : " << User.UserName << endl;
        cout << "Password     : " << User.Password << endl;
        cout << "Permissions  : " << User.Permission << endl;


    }
public:
    
    static void ShowFindUserScreen() {
    

        DrawHeaderScreen("Find User Screen");
        string userName;
        cout << "Please enter user Name : ";
        userName = clsInputValidate<string>::ReadString();
        while (!clsUser::IsExist (userName)) {
            cout << "User is not Exist !!\n";
            cout << "Please enter user Name : ";
            userName = clsInputValidate<string>::ReadString();

        
        }
        clsUser CurrUser = clsUser::Find(userName);
        if (!CurrUser.IsEmpty()) {
            cout << "User Found (:\n";
        }
        else {
            cout << "User Not Found (:\n";

        }

        _PrintUserCard(CurrUser);
    
    
    }


};

