#pragma once
#include"clsScreen.h";
#include"clsInputValidate.h";
#include<iomanip>
#include"clsBankUser.h";
#include"clsListUserScreen.h";
#include"clsAddNewUserScreen.h";
#include"clsUpdateUserScreen.h";
#include"clsDeleteUserScreen.h";
#include"clsFindUserScreen.h";
#include"Global.h";

class clsManageUsersScreen : protected clsScreen
{
private:
    enum enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };
    static int _listMangeUser()
    {
        int Counter = 0;
        cout << setw(45) << left << "" << "\t\t[" << ++Counter << "] Show User List.\n";
        cout << setw(45) << left << "" << "\t\t[" << ++Counter << "] Add New User.\n";
        cout << setw(45) << left << "" << "\t\t[" << ++Counter << "] Delete User.\n";
        cout << setw(45) << left << "" << "\t\t[" << ++Counter << "] Update User.\n";
        cout << setw(45) << left << "" << "\t\t[" << ++Counter << "] Find User.\n";
        cout << setw(45) << left << "" << "\t\t[" << ++Counter << "] Main Menu.\n";
        return Counter;
    }
    static enManageUsersMenueOptions ReadManageUsersMenueOption()
    {
        short Choice;
        cin >> Choice;
        return enManageUsersMenueOptions(Choice);
    }

    static void _GoBackToManageUsersMenue()
    {
        cout << "\n\n";
        cout << setw(37) << left << "" <<"Press any key to go back to Manage Users Menue...";
        system("pause>0");
        ShowManageUsersMenue();
    }

    static void _ShowListUsersScreen()
    {
        clsListUsersScreen::ShowUsersList();

    }

    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::AddNewUser();

    }

    static void _ShowDeleteUserScreen()
    {
        clsDeleteUserScreen::DeleteUser();

    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::UpdateUser();
    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }


    static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
    {

        switch (ManageUsersMenueOption)
        {
        case enManageUsersMenueOptions::eListUsers:
        {
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eFindUser:
        {
            system("cls");

            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
            break;
        }
        default:
        {
            cout << "Invalid Entry, Please Enter And Try Again.\n";
            _GoBackToManageUsersMenue();
            break;
        }
        }

    }



public:


    static void ShowManageUsersMenue()
    {
        if (!CheckAccessRights(7))
            return;
        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");
        cout << setw(45) << left << "" << "===========================================\n";
        cout << setw(45) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(45) << left << "" << "===========================================\n";
        int Count = _listMangeUser();
        cout << setw(45) << left << "" << "===========================================\n";
        cout << setw(45) << left << "" << "Choose What Do You Want To Do ? [1 to " << Count << "] ? ";
        _PerformManageUsersMenueOption(ReadManageUsersMenueOption());
    }
};

