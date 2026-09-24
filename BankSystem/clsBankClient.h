#pragma once
#include"clsPerson.h";
#include"clsString.h";
#include<fstream>
#include"Global.h";

class clsBankClient : public clsPerson
{
private:
	enum enMode { EmptyMode = 0 , UpdateMode = 1  , AddNewMode = 2};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	int _AccountBalance;
	bool _MarkedForDelete = false;
	static string _ConvertClientRecordToLine(clsBankClient ClientData, string Seperator = "#//#")
	{
		string Data = "";
		Data += ClientData._AccountNumber + Seperator;
		Data += ClientData.PinCode + Seperator;
		Data += ClientData.FirstName + Seperator;
		Data += ClientData.LastName + Seperator;
		Data += ClientData.Email + Seperator;
		Data += ClientData.Phone + Seperator;
		Data += to_string(ClientData.AccountBalance);
		return Data;
	}
	static clsBankClient _ConvertClientLineToObject(string Client, string Seperator = "#//#")
	{
		vector<string> vData = clsString::Split(Client, Seperator);
		return clsBankClient ( enMode::UpdateMode ,vData[0],vData[1],vData[2], vData[3], vData[4],vData[5],stod(vData[6]));
	}
	static bool _AreYouSure(string Massage = "Y/N ? ")
	{
		char Check;
		cout << Massage;
		cin >> Check;
		return (Check == 'Y' || Check == 'y');
	}
	static vector<clsBankClient> _LoadClientDataFromFile()
	{
		vector<clsBankClient> vData;
		fstream fClientData;
		fClientData.open("Client Data.text", ios::in);
		if (fClientData.is_open())
		{
			string line;
			while (getline(fClientData, line))
			{
				clsBankClient Client = _ConvertClientLineToObject(line);
				vData.push_back(Client);
			}
		}
		fClientData.close();
		return vData;
	}
	void _RecordClientDataFromFileToVector(vector<clsBankClient> DataAfterUpdate)
	{
		fstream fClientData;
		fClientData.open("Client Data.text", ios::out);
		if (fClientData.is_open())
		{
			string line;
			for (clsBankClient& Client : DataAfterUpdate)
			{
				if(Client.MarkedForDelete() == false)
				{
					line = _ConvertClientRecordToLine(Client);
					fClientData << line << endl;
				}
			}
		}
		fClientData.close();
	}
	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	void _Update()
	{
		vector<clsBankClient> _vClients;
		_vClients = _LoadClientDataFromFile();
		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_RecordClientDataFromFileToVector(_vClients);
	}
	void _AddNew()
	{
		vector<clsBankClient> _vClients;
		_vClients = _LoadClientDataFromFile();
		_vClients.push_back(*this);
		_RecordClientDataFromFileToVector(_vClients);
	}
public:
	clsBankClient(enMode Mode , string AccountNumber , string PinCode , 
		string FirstName, string LastName, string Email,
		string Phone, int AccountBalace)
		: clsPerson(FirstName , LastName , Email , Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalace;
	}
	bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}
	string AccountNumber()
	{
		return _AccountNumber;
	}
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
	void SetAccountBalance(int AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	int GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) int AccountBalance;
	/*void Print()
	{
		cout << "\nClient Card : ";
		cout << "\n________________________\n\n";
		cout << "First Name      : " << FirstName << endl;
		cout << "Last Name       : " << LastName << endl;
		cout << "Full Name       : " << GetFullName() << endl;
		cout << "Email           : " << Email << endl;
		cout << "Phone           : " << Phone << endl;
		cout << "Account Number  : " << _AccountNumber << endl;
		cout << "PinCode         : " << _PinCode << endl;
		cout << "Balance         : " << _AccountBalance << endl;
		cout << "________________________\n";
	}*/
	static clsBankClient Find(string AccountNumber)
	{
		vector<clsBankClient> vData;
		fstream fClientData;
		fClientData.open("Client Data.text", ios::in);
		if (fClientData.is_open())
		{
			string line;
			
			while (getline(fClientData, line))
			{
				clsBankClient Client = _ConvertClientLineToObject(line);
				if (Client.AccountNumber() == AccountNumber)
				{
					fClientData.close();
					return Client;
				}
				vData.push_back(Client);
			}
		}
		fClientData.close();
		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string AccountNumber , string PinCod)
	{
		vector<clsBankClient> vData;
		fstream fClientData;
		fClientData.open("Client Data.text", ios::in);
		if (fClientData.is_open())
		{
			string line;

			while (getline(fClientData, line))
			{
				clsBankClient Client = _ConvertClientLineToObject(line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCod)
				{
					fClientData.close();
					return Client;
				}
				vData.push_back(Client);
			}
		}
		fClientData.close();
		return _GetEmptyClientObject();
	}
	static clsBankClient GetAddNewClientObject(string AccounNumber)
	{
		return clsBankClient(enMode::AddNewMode, AccounNumber , "" , "" , "" , "" , "" , 0);
	}
	static bool IsClientExsit(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}
	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}
	bool Delete()
	{
		vector<clsBankClient> _vClients;
		_vClients = _LoadClientDataFromFile();
		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C._MarkedForDelete = true;
				break;
			}
		}
		_RecordClientDataFromFileToVector(_vClients);
		*this = _GetEmptyClientObject();
		return true;
	}
	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientDataFromFile();
	}
	void Deposit(int Amount)
	{
		AccountBalance += Amount;
		Save();
	}
	void Withdraw(int Amount)
	{
		AccountBalance -= Amount;
		Save();
	}
	static long long TotalBalance()
	{
		long long Total = 0;
		vector<clsBankClient> Clients = _LoadClientDataFromFile();
		for (int i = 0; i < Clients.size(); i++)
		{
			Total += Clients[i].AccountBalance;
		}
		return Total;
	}

	enum enSaveResults{svFailEmptyObject = 0 , svSucceeded = 1 , svFailAccountNumberExists = 2};
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if(IsEmpty())
				return enSaveResults::svFailEmptyObject;

		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
		}
		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExsit(_AccountNumber))
				return enSaveResults::svFailAccountNumberExists;
			_AddNew();
			_Mode = enMode::UpdateMode;
			return enSaveResults::svSucceeded;
		}
		}
	}
	static string ClientAsString(clsBankClient Client)
	{
		string Delim = " , ";
		string sClient = "( ";
		sClient +=  (Client.AccountNumber().substr(1 ,3));
		sClient += Delim;
		sClient += "\'" + Client.FirstName + "\'";
		sClient += Delim;
		sClient += "\'" + Client.LastName + "\'";
		sClient += Delim;
		sClient += to_string(Client.AccountBalance);
		sClient += Delim;
		sClient += "\'" + Client.Phone + "\'";
		sClient += " ) ,";
		return sClient;
		
	}
	static void PrintClients()
	{
		vector<clsBankClient> Clients = _LoadClientDataFromFile();
		for (clsBankClient Client : Clients)
			cout << ClientAsString(Client) << endl;
	}

};

