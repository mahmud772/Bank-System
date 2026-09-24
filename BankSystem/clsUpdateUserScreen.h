#pragma once
#include"clsScreen.h";
#include"clsInputValidate.h";
#include<iomanip>
#include"clsBankUser.h";
class clsUpdateUserScreen : protected clsScreen
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
    static void UpdateUser()
    {
        _DrawScreenHeader("\tUpdate User Screen");
        string UserName;
        cout << "Enter User Name : ";
        cin >> UserName;
        string Massage = "Are You Sure You Want Update This User ? Y/N ? ";
        while (!clsBankUser::IsUserExsit(UserName))
        {
            cout << "User With User Name (" << UserName << ") Is Not Found!" << endl;
            cout << "Enter User Name : ";
            cin >> UserName;
        }
        if (!_AreYouSure(Massage))
            return;
        clsBankUser User = clsBankUser::Find(UserName);
        _PrintUser(User);
        cout << "\n___________________________________\n";
        cout << "\n\tUpdate User Info : \n";
        cout << "___________________________________\n";
        _ReadUserInfo(User);
        cout << "___________________________________\n\n";
        clsBankUser::enSaveResults SaveResult;
        SaveResult = User.Save();
        switch (SaveResult)
        {
        case clsBankUser::enSaveResults::svSucceeded:
        {
            cout << "\n Account Update Successfuly : \n";
            _PrintUser(User);
            break;
        }
        case clsBankUser::enSaveResults::svFailEmptyObject:
        {
            cout << "\nError Account Was Not Saved Becaus Is Empty\n";
            break;
        }
        }
    }
};

