#include<iostream>
#include"clsLoginScreen.h";
using namespace std;
int main()
{
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }
    //clsBankClient::PrintClients();
    system("pause>0");
    return 0;
}