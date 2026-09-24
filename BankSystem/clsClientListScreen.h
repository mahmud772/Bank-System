#pragma once
#include"clsScreen.h";
#include"clsInputValidate.h";
#include<iomanip>
#include"clsBankClient.h";
class clsClientListScreen : protected clsScreen
{
private:
    static void _PrintClientRecord(clsBankClient Client)
    {
        cout << "\t| " << setw(15) << left << Client.AccountNumber();
        cout << "\t| " << setw(10) << left << Client.PinCode;
        cout << "\t| " << setw(20) << left << Client.GetFullName();
        cout << "\t| " << setw(20) << left << Client.Email;
        cout << "\t| " << setw(12) << left << Client.Phone;
        cout << "\t| " << setw(12) << left << Client.AccountBalance;
    }
public:
    static void ShowClientsList()
    {
        if (!CheckAccessRights(1))
            return;
        vector<clsBankClient> Data = clsBankClient::GetClientsList();
        string SubTitle = "\t   (" + to_string(Data.size()) + ") Client(s)";
        _DrawScreenHeader("\t  Client List Screen", SubTitle);
        cout << "\n\t_________________________________________________________________________________________________________________\n" << endl;
        cout << "\t| " << left << setw(15) << "AccountNumber";
        cout << "\t| " << left << setw(10) << "PinCode";
        cout << "\t| " << left << setw(20) << "Name";
        cout << "\t| " << left << setw(20) << "Email";
        cout << "\t| " << left << setw(12) << "Phone";
        cout << "\t| " << left << setw(12) << "Balance";
        cout << "\n\t_________________________________________________________________________________________________________________\n" << endl;
        for (clsBankClient& Client : Data)
        {
            _PrintClientRecord(Client);
            cout << endl;
        }
        cout << "\n\t_________________________________________________________________________________________________________________\n" << endl;

    }
};

