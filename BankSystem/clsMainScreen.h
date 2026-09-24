#pragma once
#include"clsScreen.h";
#include"clsInputValidate.h";
#include<iomanip>
#include"clsBankClient.h";
#include"clsClientListScreen.h";
#include"clsAddNewClientScreen.h";
#include"clsDeleteClientScreen.h";
#include"clsUpdateClientScreen.h";
#include"clsFindClientScreen.h";
#include"clsTransactionsScreen.h";
#include"clsManageUsersScreen.h";
#include"Global.h";
class clsMainScreen : protected clsScreen 
{
private:
	
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eExit = 8
    };

    static enMainMenueOptions _ReadMainMenueOption()
    {
        short Choice;
        cin >> Choice;
        return enMainMenueOptions(Choice);
    }
    static int _listMainMenue()
    {
        int Counter = 0;
        cout << setw(37) << left << "" << "\t\t\t[" << ++Counter << "] Show Client List.\n";
        cout << setw(37) << left << "" << "\t\t\t[" << ++Counter << "] Add New Client.\n";
        cout << setw(37) << left << "" << "\t\t\t[" << ++Counter << "] Delete Client.\n";
        cout << setw(37) << left << "" << "\t\t\t[" << ++Counter << "] Update Client.\n";
        cout << setw(37) << left << "" << "\t\t\t[" << ++Counter << "] Find Client.\n";
        cout << setw(37) << left << "" << "\t\t\t[" << ++Counter << "] Transactions.\n";
        cout << setw(37) << left << "" << "\t\t\t[" << ++Counter << "] Mange User.\n";
        cout << setw(37) << left << "" << "\t\t\t[" << ++Counter << "] Logout.";
        return Counter;
    }
    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }
    

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();

    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::AddNewClient();

    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::DeleteClient();

    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::UpdateClient();

    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();

    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionMenue();

    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();

    }

    static void _Logout()
    {
        CurrentUser = clsBankUser::Find("", "");

    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();

            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            //Login();

            break;
        default:
        {
            cout << "Invalid Entry, Please Enter And Try Again.\n";
            _GoBackToMainMenue();
            break;
        }
        }

    }



public:


    static void ShowMainMenue()
    {
        system("cls");
        _DrawScreenHeader("\t  Main Screen");
        cout << setw(37) << left << "" << "======================================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue Screen \n";
        cout << setw(37) << left << "" << "======================================================\n";
        int Count = _listMainMenue();
        cout << endl;
        cout << setw(37) << left << "" << "======================================================\n";
        cout << endl;
        cout << setw(37) << left << "" << "\tChoose What Do You Want To Do ? [1 to " << Count << "] ? ";
        _PerfromMainMenueOption(_ReadMainMenueOption());
    }
};

