#pragma once
#include"clsPerson.h";
#include"clsString.h";
#include<fstream>
class clsBankUser : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;
	static string _ConvertUserRecordToLine(clsBankUser User, string Seperator = "#//#")
	{
		string Data = "";
		Data += User.FirstName + Seperator;
		Data += User.LastName + Seperator;
		Data += User._UserName + Seperator;
		Data += User._Password + Seperator;
		Data += User.Email + Seperator;
		Data += User.Phone + Seperator;
		Data += to_string(User._Permissions);
		return Data;
	}
	static clsBankUser _ConvertUserLineToObject(string User, string Seperator = "#//#")
	{
		vector<string> vData = clsString::Split(User, Seperator);
		return clsBankUser(enMode::UpdateMode, vData[0], vData[1], vData[2], vData[3], vData[4], vData[5], stod(vData[6]));
	}
	static bool _AreYouSure(string Massage = "Y/N ? ")
	{
		char Check;
		cout << Massage;
		cin >> Check;
		return (Check == 'Y' || Check == 'y');
	}
	static vector<clsBankUser> _LoadUserDataFromFile()
	{
		vector<clsBankUser> vData;
		fstream fUserData;
		fUserData.open("User Data.text", ios::in);
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
	}
	void _RecordUserDataFromFileToVector(vector<clsBankUser> DataAfterUpdate)
	{
		fstream fUserData;
		fUserData.open("User Data.text", ios::out);
		if (fUserData.is_open())
		{
			string line;
			for (clsBankUser& User : DataAfterUpdate)
			{
				if (User.MarkedForDelete() == false)
				{
					line = _ConvertUserRecordToLine(User);
					fUserData << line << endl;
				}
			}
		}
		fUserData.close();
	}
	static clsBankUser _GetEmptyUserObject()
	{
		return clsBankUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	void _Update()
	{
		vector<clsBankUser> _vUser;
		_vUser = _LoadUserDataFromFile();
		for (clsBankUser& C : _vUser)
		{
			if (C.UserName == UserName)
			{
				C = *this;
				break;
			}
		}
		_RecordUserDataFromFileToVector(_vUser);
	}
	void _AddNew()
	{
		vector<clsBankUser> _vUsers;
		_vUsers = _LoadUserDataFromFile();
		_vUsers.push_back(*this);
		_RecordUserDataFromFileToVector(_vUsers);
	}
	
	
public:
	clsBankUser(enMode Mode, string FirstName, string LastName, 
		string UserName, string Password, string Email,
		string Phone, int Permissions)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}
	bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}
	static int Section(int Number)
	{
		int Sec = 1 << (Number - 1);
		return Sec;
	}
	bool DoYouHaveThePerimissions(int Perimissions)
	{
		return ((_Permissions & Section(Perimissions)) ? true : false);
	}
	string GetUserName()
	{
		return _UserName;
	}
	void SetUserName(string UserName)
	{
		 _UserName = UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;
	void SetPassword(string Password)
	{
		_Password = Password;
	}
	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	int GetPermissions()
	{
		return _Permissions;
	}
	void SetPermissions(int Permissions)
	{
		 _Permissions = Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;
	static int DeterminePermissions()
	{
		int Permissions = 0;
		if (_AreYouSure("Do You Want To Give Full Access ? Y/N ? "))
			return -1;
		else
		{
			cout << "Do You Want To Give Access To : \n";
			if (_AreYouSure("Show Client Lest ? Y/N ? "))
				Permissions |= Section(1);
			if (_AreYouSure("Add New Client ? Y/N ? "))
				Permissions |= Section(2);
			if (_AreYouSure("Delete Client  ? Y/N ? "))
				Permissions |= Section(3);
			if (_AreYouSure("Update Client  ? Y/N ? "))
				Permissions |= Section(4);
			if (_AreYouSure("Find Client    ? Y/N ? "))
				Permissions |= Section(5);
			if (_AreYouSure("Transcation    ? Y/N ? "))
				Permissions |= Section(6);
			if (_AreYouSure("Manage Users   ? Y/N ? "))
				Permissions |= Section(7);
		}
		return Permissions;
	}
	static clsBankUser Find(string UserName)
	{
		vector<clsBankUser> vData;
		fstream fUserData;
		fUserData.open("User Data.text", ios::in);
		if (fUserData.is_open())
		{
			string line;

			while (getline(fUserData, line))
			{
				clsBankUser User = _ConvertUserLineToObject(line);
				if (User.UserName == UserName)
				{
					fUserData.close();
					return User;
				}
				vData.push_back(User);
			}
		}
		fUserData.close();
		return _GetEmptyUserObject();
	}
	static clsBankUser Find(string UserName, string Password)
	{
		vector<clsBankUser> vData;
		fstream fUserData;
		fUserData.open("User Data.text", ios::in);
		if (fUserData.is_open())
		{
			string line;

			while (getline(fUserData, line))
			{
				clsBankUser User = _ConvertUserLineToObject(line);
				if (User.UserName == UserName && User.Password == Password)
				{
					fUserData.close();
					return User;
				}
				vData.push_back(User);
			}
		}
		fUserData.close();
		return _GetEmptyUserObject();
	}
	static clsBankUser GetAddNewUserObject(string UserName)
	{
		return clsBankUser(enMode::AddNewMode,  "", "", UserName, "", "", "", 0);
	}
	static bool IsUserExsit(string UserName)
	{
		clsBankUser User = clsBankUser::Find(UserName);
		return (!User.IsEmpty());
	}
	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}
	bool Delete()
	{
		vector<clsBankUser> _vUsers;
		_vUsers = _LoadUserDataFromFile();
		for (clsBankUser& U : _vUsers)
		{
			if (U.UserName == UserName)
			{
				U._MarkedForDelete = true;
				break;
			}
		}
		_RecordUserDataFromFileToVector(_vUsers);
		*this = _GetEmptyUserObject();
		return true;
	}
	static vector<clsBankUser> GetUsersList()
	{
		return _LoadUserDataFromFile();
	}

	enum enSaveResults { svFailEmptyObject = 0, svSucceeded = 1, svFailUserNameExists = 2 };
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
				return enSaveResults::svFailEmptyObject;

		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
		}
		case enMode::AddNewMode:
		{
			if (clsBankUser::IsUserExsit(_UserName))
				return enSaveResults::svFailUserNameExists;
			_AddNew();
			_Mode = enMode::UpdateMode;
			return enSaveResults::svSucceeded;
		}
		}
	}
};

