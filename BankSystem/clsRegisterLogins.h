#pragma once
#include"clsPerson.h";
#include"clsString.h";
#include<fstream>
#include"Global.h";
#include"clsDate.h";
class clsRegisterLogins 
{
private:
	static string _ConvertUserRecordToLine(clsBankUser User, string Seperator = "#//#")
	{
		string Data = "";
		clsDate Date;
		Data += Date.SystemDateYMDHMS() + Seperator;
		Data += User.UserName + Seperator;
		Data += User.Password + Seperator;
		Data += to_string(User.Permissions);
		return Data;
	}
	/*static clsBankUser _ConvertUserLineToObject(string User, string Seperator = "#//#")
	{
		vector<string> vData = clsString::Split(User, Seperator);
		return clsBankUser(enMode::UpdateMode, vData[0], vData[1], vData[2], vData[3], vData[4], vData[5], stod(vData[6]));
	}*/
	static bool _AreYouSure(string Massage = "Y/N ? ")
	{
		char Check;
		cout << Massage;
		cin >> Check;
		return (Check == 'Y' || Check == 'y');
	}
	/*static vector<clsBankUser> _LoadUserDataFromFile()
	{
		vector<clsBankUser> vData;
		fstream fUserData;
		fUserData.open("Register Logins.text", ios::in);
		if (fUserData.is_open())
		{
			string line;
			while (getline(fUserData, line))
			{
				clsBankUser User = _ConvertUserLineToObject(line);
				vData.push_back(User);
			}
		}
		fUserData.close();
		return vData;
	}*/
	static void _RecordUserDataFromFileToVector(clsBankUser User)
	{
		fstream fUserData;
		fUserData.open("Register Logins.text", ios::app);
		if (fUserData.is_open())
		{
			string line;
			
			
				//if (User.MarkedForDelete() == false)
				{
					line = _ConvertUserRecordToLine(User);
					fUserData << line << endl;
				}
			
		}
		fUserData.close();
	}
	/*static clsBankUser _GetEmptyUserObject()
	{
		return clsBankUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}*/
public:
	static void RegistLogins(clsBankUser User)
	{
		_RecordUserDataFromFileToVector(User);
	}
};

