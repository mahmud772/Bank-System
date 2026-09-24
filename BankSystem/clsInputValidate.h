#pragma once
#include<iostream>
#include<string>
using namespace std;

class clsInputValidate
{
private:

public:
    static int ReadPositiveNumber(string Massage)
    {
        int Number;
        cout << Massage;
        cin >> Number;
        while (cin.fail() || Number < 0)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number , Enter a Valid One : ";
            cin >> Number;
        }
        return Number;
    }
    static int ReadPositiveNumber()
    {
        int Number;
        cin >> Number;
        while (cin.fail() || Number < 0)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number , Enter a Valid One : ";
            cin >> Number;
        }
        return Number;
    }
    static int ReadNumber(string Massage)
    {
        int Number;
        cout << Massage;
        cin >> Number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number , Enter a Valid One : ";
            cin >> Number;
        }
        return Number;
    }
    static int ReadNumber(string Massage, int From, int To)
    {
        int Number;
        cout << Massage;
        cin >> Number;
        while (cin.fail() || Number < From || Number > To)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number , Enter a Valid One : ";
            cin >> Number;
        }
        return Number;
    }
    static int ReadNumber()
    {
        int Number;
        cin >> Number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number , Enter a Valid One : ";
            cin >> Number;
        }
        return Number;
    }
    static int ReadNumber(int From, int To)
    {
        int Number;
        cin >> Number;
        while (cin.fail() || Number < From || Number > To)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number , Enter a Valid One : ";
            cin >> Number;
        }
        return Number;
    }
    static float ReadPositiveFloatNumber(string Massage)
    {
        float Number;
        cout << Massage;
        cin >> Number;
        while (cin.fail() || Number < 0)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number , Enter a Valid One : ";
            cin >> Number;
        }
        return Number;
    }
    static float ReadPositiveFloatNumber()
    {
        float Number;
        cin >> Number;
        while (cin.fail() || Number < 0)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number , Enter a Valid One : ";
            cin >> Number;
        }
        return Number;
    }
    static float ReadFloatNumber(string Massage)
    {
        float Number;
        cout << Massage;
        cin >> Number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number , Enter a Valid One : ";
            cin >> Number;
        }
        return Number;
    }
    static float ReadFloatNumber()
    {
        float Number;
        cin >> Number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number , Enter a Valid One : ";
            cin >> Number;
        }
        return Number;
    }
    static char ReadChar(string Massage)
    {
        char Character;
        cout << Massage;
        cin >> Character;
        return Character;
    }
    static char ReadChar()
    {
        char Character;
        cin >> Character;
        return Character;
    }
    static string ReadString(string Massage)
    {
        string String;
        cout << Massage;
        getline(cin >> ws, String);
        return String;
    }
    static string ReadString()
    {
        string String;
        getline(cin >> ws, String);
        return String;
    }
    static string ReadWord(string Massage)
    {
        string String;
        cout << Massage;
        cin >> String;
        return String;
    }
    static string ReadWord()
    {
        string String;
        cin >> String;
        return String;
    }
    static bool IsNumberBetween(int Number, int From, int To)
    {
        return (Number > From && Number < To);
    }
    static bool IsNumberBetween(float Number, float From, float To)
    {
        return (Number > From && Number < To);
    }
    static bool IsNumberBetween(double Number, double From, double To)
    {
        return (Number > From && Number < To);
    }
};

