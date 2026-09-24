#pragma once
#include "clsScreen.h"
#include "clsBankUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
#include"clsRegisterLogins.h";
class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;
        int FaildLoginCount = 0;
        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                FaildLoginCount++;
                cout << "\nInvlaid Username/Password!\n\n";
                cout << "\nYou Have " << (3 - FaildLoginCount) << " Trial(s) To Login.\n";
            }
            if (FaildLoginCount == 3)
            {
                cout << "\nYou Are Locked After 3 Faild Trials.\n";
                return false;
            }
            cout << "Enter Username : ";
            cin >> Username;

            cout << "Enter Password : ";
            cin >> Password;

            CurrentUser = clsBankUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);
        clsRegisterLogins::RegistLogins(CurrentUser);
        clsMainScreen::ShowMainMenue();
        return true;

    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};


