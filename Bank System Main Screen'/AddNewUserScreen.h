#pragma once
#include "clsScreen.h"
#include"clsUser.h"
#include"../../clsInputValidate.h"
class AddNewUserScreen :
    protected clsScreen
{
private:
  
    static  void _PrintUserCard(clsUser &User) {
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
    static void _ReadUserInfo(clsUser &User) {
        cout << "Enter First Name : ";
        User.FirstName = clsInputValidate<string>::ReadString();
        cout << "Enter Last Name  : ";
        User.LastName = clsInputValidate<string>::ReadString();
        cout << "Enter Email      : ";
        User.Email = clsInputValidate<string>::ReadString();
        cout << "Enter Phone      : ";
        User.Phone = clsInputValidate<string>::ReadString();
        cout << "Enter Password   : ";
        User.Password = clsInputValidate<string>::ReadString();
        cout << "Enter Permission : ";
        User.Permission =_ReadPermission();
    }
    static int _ReadPermission() {
        char UserChoice;
        int Permission=0;
        cout << "Do you want to give all access [y/n]\n";
        cin >> UserChoice;
        if (tolower(UserChoice)=='y') {
            Permission += clsUser::enPermission::pAll;
            return Permission;
        }
        cout << "Show Clients [y/n]\n";
        cin >> UserChoice;
        if (tolower(UserChoice) == 'y') {
            Permission += clsUser::enPermission::pShowClientList;
  
        }
        cout << " Add New Client [y/n]\n";
        cin >> UserChoice;
        if (tolower(UserChoice) == 'y') {
            Permission += clsUser::enPermission::pAddNewClient;

        } 
        cout << " Delete Client [y/n]\n";
        cin >> UserChoice;
        if (tolower(UserChoice) == 'y') {
            Permission += clsUser::enPermission::pDeleteClient;

        }
        cout << "Update Client [y/n]\n";
        cin >> UserChoice;
        if (tolower(UserChoice) == 'y') {
            Permission += clsUser::enPermission::pUpdateClient;

        }
        cout << "Find Client [y/n]\n";
        cin >> UserChoice;
        if (tolower(UserChoice) == 'y') {
            Permission += clsUser::enPermission::pFindClient;

        }
        cout << "Trancactions Client [y/n]\n";
        cin >> UserChoice;
        if (tolower(UserChoice) == 'y') {
            Permission += clsUser::enPermission::pTrancaction;

        }  
        cout << "Manage Users  [y/n]\n";
        cin >> UserChoice;
        if (tolower(UserChoice) == 'y') {
            Permission += clsUser::enPermission::pManageUser;

        }
        cout << "Show Login Register  [y/n]\n";
        cin >> UserChoice;
        if (tolower(UserChoice) == 'y') {
            Permission += clsUser::enPermission::pShowLoginRegister;

        }
        return Permission;

    }
public:
    
    static void ShowAddNewUserScreen() {
      
        DrawHeaderScreen("Add New User Screen");
        cout << "Enter User Name : ";
        string UserName = clsInputValidate<string>::ReadString();
        while (clsUser::IsExist(UserName)) {
            cout << "Error !! User Exist \n";
            cout << "Enter User Name : ";
            UserName = clsInputValidate<string>::ReadString();
        }
        clsUser NewUser = clsUser::GetNewUserObject(UserName);
        _ReadUserInfo(NewUser);

        clsUser::enSave Save = NewUser.Save();
        switch (Save) {
        case clsUser::enSave::svFaildEmptyObject:
            cout << "Failed User Save Empty Object :(  !! ";
            break;
        case clsUser::enSave::svFaillUserExist:
                cout << "Failed, User Already Exists. :(  !!";
                break;
        case clsUser::enSave::svSuccessed:
            cout << "Succeeded User Save (: ";
            _PrintUserCard(NewUser);
            break;
        
        default: cout << "Faild User Save :(  !!";

        }


    
    }


};

