#pragma once
#include"clsLoginScreen.h";
class clsLogoutScreen 
{
private:

public:
	static void Logout()
	{
		clsLoginScreen::ShowLoginScreen();
	}
};

