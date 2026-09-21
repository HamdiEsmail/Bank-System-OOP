#pragma once
#include "clsScreen.h"
#include"clsUser.h"
#include<iomanip>
class clsUsersListScreen :
    protected clsScreen
{
private:
    static void _PrintUser(clsUser User) {
    
        cout << "| " << left << setw(25) << User.getFullName();
        cout << "| " << left << setw(10) << User.UserName;
        cout << "| " << left << setw(12) << User.Phone;
        cout << "| " << left << setw(20) << User.Email;
        cout << "| " << left << setw(10) << User.Password;
        cout << "| " << left << setw(12) << User.Permission << endl;
        
   
        
    

    }
public:

    static void ShowUserListScreen() {
      vector<clsUser>vAllUsers=  clsUser::GetUserList();
      string Title = "User List Screen ";
      string SubTitle = "("+to_string(vAllUsers.size())+") User(s)";
      DrawHeaderScreen(Title,SubTitle);
      cout <<"" << "__________________________________________________________________________________\n";
      cout <<"" << "| " << left << setw(25) << "Full Name";
      cout <<"" << "| " << left << setw(10) << "UserName";

      cout <<"" << "| " << left << setw(12) << "Phone";
      cout <<"" << "| " << left << setw(20) << "Email";
      cout <<"" << "| " << left << setw(10) << "Password";
      cout <<"" << "| " << left << setw(12) << "Permission" << endl;
      cout <<"" << "__________________________________________________________________________________\n";
      for (clsUser &CurrUser:vAllUsers) {
          _PrintUser(CurrUser);
      
      }
    
    }
};

