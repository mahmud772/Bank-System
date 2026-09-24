#pragma once
#include"clsScreen.h";
#include"clsInputValidate.h";
#include<iomanip>
#include"clsBankUser.h";
class clsFindUserScreen : protected clsScreen
{
private:
    static void _PrintUser(clsBankUser User)
    {
        cout << "\nUser Card : ";
        cout << "\n________________________\n\n";
        cout << "First Name      : " << User.FirstName << endl;
        cout << "Last Name       : " << User.LastName << endl;
        cout << "Full Name       : " << User.GetFullName() << endl;
        cout << "Email           : " << User.Email << endl;
        cout << "Phone           : " << User.Phone << endl;
        cout << "User Name       : " << User.UserName << endl;
        cout << "Password        : " << User.Password << endl;
        cout << "Permissions     : " << User.Permissions << endl;
        cout << "________________________\n";
    }
public:
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\t  Find User Screen");
        string UserName;
        cout << "Enter User Name : ";
        cin >> UserName;
        string Massage = "Are You Sure You Want Delete This User ? Y/N ? ";
        while (!clsBankUser::IsUserExsit(UserName))
        {
            cout << "User With User Name (" << UserName << ") Is Not Found!" << endl;
            cout << "Enter User Name : ";
            cin >> UserName;
        }
        clsBankUser User = clsBankUser::Find(UserName);
        _PrintUser(User);
    }
};

