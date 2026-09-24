#pragma once
#include<iostream>
#include"Global.h";
#include"clsDate.h";
#include <iomanip>
using namespace std;
class clsScreen
{
private:
    static void _PrintDate()
    {
        clsDate Date;
        Date.PrintDate();
    }
protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
       
        
        cout << "User : " << setw(18) << CurrentUser.UserName;
        cout << setw(20) << left << "" << "______________________________________";
        cout << "\nDate : "; _PrintDate();
        cout << endl;
        cout << setw(50) << left << ""  << Title;
        if (SubTitle != "")
        {
            cout << "\n";
            cout << setw(50) << left << "" << SubTitle;
        }
        cout <<"\n" << setw(45) << left << "" << "______________________________________\n\n";
        cout << endl;

	}

    static bool CheckAccessRights(int Permission)
    {

        if (!CurrentUser.DoYouHaveThePerimissions(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }
};

