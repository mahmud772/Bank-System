#pragma once
#include"clsScreen.h";
#include"clsInputValidate.h";
#include<iomanip>
#include"clsBankClient.h";
class clsUpdateClientScreen : protected clsScreen
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
    static void UpdateClient()
    {
        if (!CheckAccessRights(4))
            return;
        _DrawScreenHeader("\tUpdate Client Screen");
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
        if (!_AreYouSure(Massage))
            return;
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);
        cout << "\n___________________________________\n";
        cout << "\n\tUpdate Client Info : \n";
        cout << "___________________________________\n";
        _ReadClientInfo(Client);
        cout << "___________________________________\n\n";
        clsBankClient::enSaveResults SaveResult;
        SaveResult = Client.Save();
        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded :
        {
            cout << "\n Account Update Successfuly : \n";
            _PrintClient(Client);
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

