#pragma once
#include"clsScreen.h";
#include"clsInputValidate.h";
#include<iomanip>
#include"clsBankClient.h";
#include"clsDepositScreen.h";
#include"clsWithdrawScreen.h";
#include"clsTotalBalanceScreen.h";
class clsTransactionsScreen : protected clsScreen
{
private:
    enum enTransactions
    {
        eDeposit = 1,
        eWithdraw = 2,
        eTotalBalance = 3,
        eMainMenue = 4
    };
    static int _listTransctionMenue()
    {
        int Counter = 0;
        cout << setw(37) << left << "" << "\t\t\t[" << ++Counter << "] Deposit.\n";
        cout << setw(37) << left << "" << "\t\t\t[" << ++Counter << "] Withdraw.\n";
        cout << setw(37) << left << "" << "\t\t\t[" << ++Counter << "] TotalBalance.\n";
        cout << setw(37) << left << "" << "\t\t\t[" << ++Counter << "] Main Menue.\n";
        return Counter;
    }
    static enTransactions _ReadTransactionMenueOption()
    {
        short Choose;
        cin >> Choose;
        return enTransactions(Choose);
    }
    static void _GoBackToTransactionMenue()
    {
        cout << setw(37) << left << "" << "\tPress Any Key To Go Back To Transaction Menue...";
        system("pause>0");
        system("cls");
        ShowTransactionMenue();
    }
    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }
    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }
    static void _ShowTotalBalanceScreen()
    {
        clsTotalBalanceScreen::ShowTotalBalances();
    }
    static void _PerfromTransactionMenueOption(enTransactions Option)
    {
        switch (Option)
        {
        case eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionMenue();
            break;
        }
        case eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionMenue();
            break;
        }
        case eTotalBalance:
        {
            system("cls");
            _ShowTotalBalanceScreen();
            _GoBackToTransactionMenue();
            break;
        }
        case eMainMenue:
        {
            /*system("cls");*/
            //ShowMainMenue();
            break;
        }
        default:
        {
            cout << "Invalid Entry, Please Enter And Try Again.\n";
            _GoBackToTransactionMenue();
            break;
        }
        }
    }
public:
    static void ShowTransactionMenue()
    {
        if (!CheckAccessRights(6))
            return;
        _DrawScreenHeader("\t  Transaction Screen");
        cout << setw(37) << left << "" << "======================================================\n";
        cout << setw(37) << left << "" << "\t\t\tTransaction Menue Screen\n";
        cout << setw(37) << left << "" << "======================================================\n";
        int Count = _listTransctionMenue();
        cout << setw(37) << left << "" << "======================================================\n";
        cout << setw(37) << left << "" << "\t  Choose What Do You Want To Do ? [1 to " << Count << "] ? ";
        _PerfromTransactionMenueOption(_ReadTransactionMenueOption());
        //system("pause>0");

    }
};

