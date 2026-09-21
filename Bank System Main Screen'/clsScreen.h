#pragma once
#include<iostream>
#include"clsUser.h"
#include"Global.h"
#include"../../clsDate.h"
using namespace std;
class clsScreen
{
private :
	

public :

	
static	void DrawHeaderScreen(string title,string subTitle="") {
		cout << "\n\t\t\t\t_________________________________________\n\n";
		cout << "\t\t\t\t\t\t" << title;
		if (subTitle!="") {
	
			cout << "\n\t\t\t\t\t\t" << subTitle;
		}
		cout << "\n\t\t\t\t_________________________________________\n";
		clsDate Date;
	
		cout << "\n\t\t\t\t\t\t"<<"Date : ";Date.Print();
		cout << "\t\t\t\t\t\t" <<"User : " << CurrUser.UserName << endl<<endl;
		
	
	
	}
static bool CheckAccessRight(clsUser::enPermission Permission) {

	if (CurrUser.CheckAccessPermission(Permission)) return true;
	else {
		DrawHeaderScreen("Access Denied ,Contact your Admin ");
		return false;
	}
}
};

