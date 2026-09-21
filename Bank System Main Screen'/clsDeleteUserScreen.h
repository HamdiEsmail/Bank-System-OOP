#pragma once
#include "clsScreen.h"
#include"clsUser.h"
#include"../../clsInputValidate.h"
class clsDeleteUserScreen :
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
    static void ShowDeleteScreen() {
        DrawHeaderScreen("Delete Screen");
        string UserName;
        cout << "Enter User Name : ";
        UserName = clsInputValidate<string>::ReadString();
        while (!clsUser::IsExist(UserName)) {
            cout << "User is not Exist !!\n";
            cout << "Enter User Name : ";
            UserName = clsInputValidate<string>::ReadString();
        }
        clsUser CurrUser = clsUser::Find(UserName);
        _PrintUserCard(CurrUser);
        cout << "Are you sure you want to delete this user ? [y/n] : ";
        char UserChoice = 'n';
        cin >> UserChoice;
        if (tolower(UserChoice)=='y') {
            
            if (CurrUser.Delete()) {
                cout << "User Deleted succeed (: ";
                _PrintUserCard(CurrUser);
            
            
            }
            else {
                cout << "User is not deleted :( ";
            
            }
        
        }






    }
};

