#pragma once
#include"clsScreen.h";
#include"clsInputValidate.h";
#include<iomanip>
#include"clsBankClient.h";
class clsFindClientScreen : protected clsScreen
{
private:
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
    static void ShowFindClientScreen()
    {
        if (!CheckAccessRights(5))
            return;
        _DrawScreenHeader("\t  Find Client Screen");
        string AccountNumber;
        cout << "Enter Account Number : ";
        cin >> AccountNumber;
        string Massage = "Are You Sure You Want Update This Client ? Y/N ? ";
        while (!clsBankClient::IsClientExsit(AccountNumber))
        {
            cout << "Client With Account Number (" << AccountNumber << ") Is Not Found!" << endl;
            cout << "Enter Account Number : ";
            cin >> AccountNumber;
        }
        clsBankClient::Find(AccountNumber);
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);
    }
};

