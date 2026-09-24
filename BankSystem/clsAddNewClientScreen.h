#pragma once
#include"clsScreen.h";
#include"clsInputValidate.h";
#include<iomanip>
#include"clsBankClient.h";
class clsAddNewClientScreen : protected clsScreen
{
private:
    static bool _AreYouSure(string Massage = "Y/N ? ")
    {
        char Check;
        cout << Massage;
        cin >> Check;
        return (Check == 'Y' || Check == 'y');
    }
    static void _ReadClientInfo(clsBankClient& Client)
    {
        Client.FirstName = clsInputValidate::ReadString("Enter Firs Name : ");
        Client.LastName = clsInputValidate::ReadString("Enter Last Name : ");
        Client.Email = clsInputValidate::ReadString("Enter Email     : ");
        Client.Phone = clsInputValidate::ReadString("Enter Phone     : ");
        Client.PinCode = clsInputValidate::ReadString("Enter PinCode   : ");
        Client.AccountBalance = clsInputValidate::ReadNumber("Enter Balance   : ", 0, 30000);
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
    static void AddNewClient()
    {
        if (!CheckAccessRights(2))
            return;
        _DrawScreenHeader("\tAdd New Client Screen");
        string AccountNumber;
        cout << "Enter Account Number : ";
        cin >> AccountNumber;
        string Massage = "Are You Sure You Want Add This Client ? Y/N ? ";
        while (clsBankClient::IsClientExsit(AccountNumber))
        {
            cout << "Account Number Is Already Used, Choose Another One : " << endl;
            cout << "Enter Account Number : ";
            cin >> AccountNumber;
        }
        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
        _ReadClientInfo(NewClient);
        if (!_AreYouSure(Massage))
            return;
        clsBankClient::enSaveResults SaveResult;
        SaveResult = NewClient.Save();
        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\n Add New Account Successfuly : \n";
            _PrintClient(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFailEmptyObject:
        {
            cout << "\nError Account Was Not Saved Becaus Is Empty\n";
            break;
        }
        }
    }
};

