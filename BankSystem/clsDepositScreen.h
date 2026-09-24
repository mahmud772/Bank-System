#pragma once
#include"clsScreen.h";
#include"clsInputValidate.h";
#include<iomanip>
#include"clsBankClient.h";
class clsDepositScreen : protected clsScreen
{
private:
    static bool _AreYouSure(string Massage = "Y/N ? ")
    {
        char Check;
        cout << Massage;
        cin >> Check;
        return (Check == 'Y' || Check == 'y');
    }
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card : ";
        cout << "\n________________________\n\n";
        cout << "First Name      : " << Client.FirstName << endl;
        cout << "Last Name       : " << Client.LastName << endl;
        cout << "Full Name       : " << Client.GetFullName() << endl;
        cout << "Email           : " << Client.Email << endl;
        cout << "Phone           : " << Client.Phone << endl;
        cout << "Account Number  : " << Client.AccountNumber() << endl;
        cout << "PinCode         : " << Client.PinCode << endl;
        cout << "Balance         : " << Client.AccountBalance << endl;
        cout << "________________________\n";
    }
public:
    static void ShowDepositScreen()
    {
        
        _DrawScreenHeader("\tDeposit Screen");
        string AccountNumber;
        cout << "Enter Account Number : ";
        cin >> AccountNumber;
        string Massage = "Are You Sure You Want Perfrom This Transaction ? Y/N ? ";
        while (!clsBankClient::IsClientExsit(AccountNumber))
        {
            cout << "Client With Account Number (" << AccountNumber << ") Is Not Found!" << endl;
            cout << "Enter Account Number : ";
            cin >> AccountNumber;
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);
        cout << "Enter Deposit Amount : ";
        int Amount;
        cin >> Amount;
        if (!_AreYouSure(Massage))
            return;
        Client.Deposit(Amount);
        cout << "Done Successfully \nNew Balance = " << Client.AccountBalance << endl;
    }
};

