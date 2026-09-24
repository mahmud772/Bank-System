#pragma once
#include"clsScreen.h";
#include"clsInputValidate.h";
#include<iomanip>
#include"clsBankUser.h";
class clsDeleteUserScreen : protected clsScreen
{
private:
    static bool _AreYouSure(string Massage = "Y/N ? ")
    {
        char Check;
        cout << Massage;
        cin >> Check;
        return (Check == 'Y' || Check == 'y');
    }
    static void _ReadUserInfo(clsBankUser& User)
    {
        User.FirstName = clsInputValidate::ReadString("Enter Firs Name : ");
        User.LastName = clsInputValidate::ReadString("Enter Last Name : ");
        User.Email = clsInputValidate::ReadString("Enter Email     : ");
        User.Phone = clsInputValidate::ReadString("Enter Phone     : ");
        User.Password = clsInputValidate::ReadString("Enter Password  : ");
        //User.UserName =  clsInputValidate::ReadString("Enter User Name : ");
        User.Permissions = clsBankUser::DeterminePermissions();
    }
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
    static void DeleteUser()
    {
        _DrawScreenHeader("\tDelete User Screen");
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
        if (!_AreYouSure(Massage))
            return;
        if (User.Delete())
        {
            cout << "\nAccount Delete Successfuly : \n";
            _PrintUser(User);
        }
        else
        {
            cout << "\nError Account Was Not Delete\n";
        }
    }
};

