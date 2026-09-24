#pragma once
#include"clsScreen.h";
#include"clsInputValidate.h";
#include<iomanip>
#include"clsBankUser.h";
class clsAddNewUserScreen : protected clsScreen
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
        User.LastName =  clsInputValidate::ReadString("Enter Last Name : ");
        User.Email =     clsInputValidate::ReadString("Enter Email     : ");
        User.Phone =     clsInputValidate::ReadString("Enter Phone     : ");
        User.Password =  clsInputValidate::ReadString("Enter Password  : ");
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
    static void AddNewUser()
    {
        _DrawScreenHeader("\t  Add New User Screen");
        string UserName;
        cout << "Enter User Name : ";
        cin >> UserName;
        string Massage = "Are You Sure You Want Add This User ? Y/N ? ";
        while (clsBankUser::IsUserExsit(UserName))
        {
            cout << "User Name Is Already Used, Choose Another One : " << endl;
            cout << "Enter User Name : ";
            cin >> UserName;
        }
        clsBankUser NewUser = clsBankUser::GetAddNewUserObject(UserName);
        _ReadUserInfo(NewUser);
        if (!_AreYouSure(Massage))
            return;
        clsBankUser::enSaveResults SaveResult;
        SaveResult = NewUser.Save();
        switch (SaveResult)
        {
        case clsBankUser::enSaveResults::svSucceeded:
        {
            cout << "\n Add New Account Successfuly : \n";
            _PrintUser(NewUser);
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

