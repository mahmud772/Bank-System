#pragma once
#define clear_buffer cin.ignore(numeric_limits<streamsize>::max(), '\n');
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include "clsInputValidate.h";
#include "clsUtil.h";
class clsString
{
private:
    string MyString;
protected:
    static char ToUpperChar(char Char)
    {
        if (Char > 96 && Char < 122)
            return (Char - 32);
        return Char;
    }
    static char ToLowerChar(char Char)
    {
        if (Char > 64 && Char < 90)
            return (Char + 32);
        return Char;
    }
    static bool IsUpperChar(char Char)
    {
        return (Char <= 90 && Char >= 65);
    }
    static bool IsLowerChar(char Char)
    {
        return (Char <= 121 && Char >= 97);
    }
    static char ChangeCharacterCase(char Char)
    {
        return (IsUpperChar(Char) ? ToLowerChar(Char) : ToUpperChar(Char));
    }
    static bool IsSameCharacter(char Char1, char Char2)
    {
        return (Char1 == Char2 ? true : false);
    }
    static bool IsVowel(char Char)
    {
        Char = ToLowerChar(Char);
        return (Char == 'a' || Char == 'e' || Char == 'i' || Char == 'o' || Char == 'u');
    }
public:
    clsString()
    {
        MyString = "";
    }
    clsString(string sString)
    {
        MyString = sString;
    }
    void SetString(string sString)
    {
        MyString = sString;
    }
    string GetString()
    {
        return MyString;
    }
    __declspec(property(get = GetString, put = SetString)) string String;
    void Print()
    {
        cout << MyString << endl;
    }
    void Print(string Message)
    {
        cout << Message;
        cout << MyString << endl;
    }
    static string UpperCaseTheFirsLetterOfEachWord(string sString)
    {
        bool IsFirstLetter = true;
        for (short i = 0; i < sString.size(); i++)
        {
            if (sString[i] != ' ' && IsFirstLetter)
                sString[i] = ToUpperChar(sString[i]);
            IsFirstLetter = (sString[i] == ' ' ? true : false);
        }
        return sString;
    }
    void UpperCaseTheFirsLetterOfEachWord()
    {
        bool IsFirstLetter = true;
        for (short i = 0; i < MyString.size(); i++)
        {
            if (MyString[i] != ' ' && IsFirstLetter)
                MyString[i] = ToUpperChar(MyString[i]);
            IsFirstLetter = (MyString[i] == ' ' ? true : false);
        }
    }
    static string UpperCaseLetterOfString(string sString)
    {
        for (short i = 0; i < sString.length(); i++)
            sString[i] = ToUpperChar(sString[i]);
        return sString;
    }
    void UpperCaseLetterOfString()
    {
        for (short i = 0; i < MyString.length(); i++)
            MyString[i] = ToUpperChar(MyString[i]);
    }
    static string LowerCaseLetterOfString(string sString)
    {
        for (short i = 0; i < sString.length(); i++)
            sString[i] = ToLowerChar(sString[i]);
        return sString;
    }
    void LowerCaseLetterOfString()
    {
        for (short i = 0; i < MyString.length(); i++)
            MyString[i] = ToLowerChar(MyString[i]);
    }
    static string InvertLattersOfString(string sString)
    {
        for (short i = 0; i < sString.size(); i++)
            sString[i] = ChangeCharacterCase(sString[i]);
        return sString;
    }
    void InvertLattersOfString()
    {
        for (short i = 0; i < MyString.size(); i++)
            MyString[i] = ChangeCharacterCase(MyString[i]);
    }
    static int CounterSmallLetters(string sString)
    {
        int Counter = 0;
        for (short i = 0; i < sString.size(); i++)
            if (IsLowerChar(sString[i]))
                Counter++;
        return Counter;
    }
    int CounterSmallLetters()
    {
        int Counter = 0;
        for (short i = 0; i < MyString.size(); i++)
            if (IsLowerChar(MyString[i]))
                Counter++;
        return Counter;
    }
    static int CounterCapitalLetters(string sString)
    {
        int Counter = 0;
        for (short i = 0; i < sString.size(); i++)
            if (IsUpperChar(sString[i]))
                Counter++;
        return Counter;
    }
    int CounterCapitalLetters()
    {
        int Counter = 0;
        for (short i = 0; i < MyString.size(); i++)
            if (IsUpperChar(MyString[i]))
                Counter++;
        return Counter;
    }
    static int CounterLetters(string sString, char Char)
    {
        int Counter = 0;
        for (int i = 0; i < sString.size(); i++)
            if (IsSameCharacter(sString[i], Char))
                Counter++;
        return Counter;
    }
    int CounterLetters(char Char)
    {
        int Counter = 0;
        for (int i = 0; i < MyString.size(); i++)
            if (IsSameCharacter(MyString[i], Char))
                Counter++;
        return Counter;
    }
    static string StorageVowelsFromString(string sString)
    {
        string StorageVowels = "";
        for (int i = 0; i < sString.size(); i++)
            if (IsVowel(sString[i]))
                StorageVowels += sString[i];
        return StorageVowels;
    }
    string StorageVowelsFromString()
    {
        string StorageVowels = "";
        for (int i = 0; i < MyString.size(); i++)
            if (IsVowel(MyString[i]))
                StorageVowels += MyString[i];
        return StorageVowels;
    }
    static int CountVowelInString(string sString)
    {
        int Counter = 0;
        for (int i = 0; i < sString.size(); i++)
            if (IsVowel(sString[i]))
                Counter++;
        return Counter;
    }
    int CountVowelInString()
    {
        int Counter = 0;
        for (int i = 0; i < MyString.size(); i++)
            if (IsVowel(MyString[i]))
                Counter++;
        return Counter;
    }
    static int CountEachWordInString(string sString)
    {
        string delim = " ";
        int pos = 0;
        string sWord;
        int Counter = 0;
        while ((pos = sString.find(delim)) != std::string::npos)
        {
            sWord = sString.substr(0, pos);
            if (sWord != "")
                Counter++;
            sString.erase(0, pos + delim.length());
        }
        if (sString != "")
            Counter++;
        return Counter;
    }
    int CountEachWordInString()
    {
        string delim = " ";
        int pos = 0;
        string sWord;
        int Counter = 0;
        while ((pos = MyString.find(delim)) != std::string::npos)
        {
            sWord = MyString.substr(0, pos);
            if (sWord != "")
                Counter++;
            MyString.erase(0, pos + delim.length());
        }
        if (MyString != "")
            Counter++;
        return Counter;
    }
    static vector<string> Split(string sString, string delim)
    {
        int pos = 0;
        string sWord;
        vector<string> vWords;
        while ((pos = sString.find(delim)) != std::string::npos)
        {
            sWord = sString.substr(0, pos);
            if (sWord != "")
                vWords.push_back(sWord);
            sString.erase(0, pos + delim.length());
        }
        if (sString != "")
            vWords.push_back(sString);
        return vWords;
    }
    vector<string> Split(string delim)
    {
        int pos = 0;
        string sWord;
        vector<string> vWords;
        while ((pos = MyString.find(delim)) != std::string::npos)
        {
            sWord = MyString.substr(0, pos);
            if (sWord != "")
                vWords.push_back(sWord);
            MyString.erase(0, pos + delim.length());
        }
        if (MyString != "")
            vWords.push_back(MyString);
        return vWords;
    }
    static string TrimLeft(string sString)
    {
        for (short i = 0; i < sString.size(); i++)
            if (sString[i] != ' ')
                return sString.substr(i, sString.size() - i);
        return "";
    }
    void TrimLeft()
    {
        for (short i = 0; i < MyString.size(); i++)
            if (MyString[i] != ' ')
            {
                MyString.substr(i, MyString.size() - i);
                return;
            }
        
    }
    static string TrimRight(string sString)
    {
        for (short i = sString.size() - 1; i >= 0; i--)
            if (sString[i] != ' ')
                return sString.substr(0, i + 1);
        return "";
    }
    void TrimRight()
    {
        for (short i = MyString.size() - 1; i >= 0; i--)
            if (MyString[i] != ' ')
            {
                MyString.substr(0, i + 1);
                return;
            }
    }
    static string Trim(string sString)
    {
        return TrimRight(TrimLeft(sString));
    }
    void Trim()
    {
        MyString = TrimRight(TrimLeft(MyString));
    }
    static string JoinString(vector<string> vString, string delim)
    {
        string String = "";
        for (string& word : vString)
        {
            String += word;
            String += delim;
        }
        return String.substr(0, (String.length() - delim.length()));
    }
    static string JoinString(string sArray[], int Size, string delim)
    {
        string String = "";
        for (short i = 0; i < Size; i++)
        {
            String += sArray[i];
            String += delim;
        }
        return String.substr(0, (String.length() - delim.length()));
    }
    static string ReversWordsInVector(vector<string> vString, string delim)
    {
        string ReversString = "";
        for (int i = vString.size() - 1; i >= 0; i--)
        {
            ReversString += vString[i];
            ReversString += delim;
        }
        return ReversString.substr(0, (ReversString.length() - delim.length()));
    }
    static string ReversWordsInString(string sString, string delim = " ")
    {
        vector<string> vString = Split(sString, delim);
        sString = ReversWordsInVector(vString, delim);
        return sString;
    }
    static string ReplaceWordInString(string sString, string WordReplace, string WordToReplace)
    {
        int pos = sString.find(WordReplace);
        while (pos != std::string::npos)
        {
            sString.replace(pos, WordReplace.length(), WordToReplace);
            pos = sString.find(WordReplace);
        }
        return sString;
    }
    void ReplaceWordInString(string WordReplace, string WordToReplace)
    {
        int pos = MyString.find(WordReplace);
        while (pos != std::string::npos)
        {
            MyString.replace(pos, WordReplace.length(), WordToReplace);
            pos = MyString.find(WordReplace);
        }
    }
    static string ReplaceWordInStringWithSplit(string String1, string WordReplace, string WordToRepalce, bool MatchCase = true)
    {
        vector<string> vString = Split(String1, " ");
        string String = "";
        for (string& Word : vString)
        {
            if (Word == WordReplace && MatchCase)
                String += WordToRepalce;
            else if (UpperCaseLetterOfString(Word) == UpperCaseLetterOfString(WordReplace) && !MatchCase)
                String += WordToRepalce;
            else
                String += Word;
            String += " ";

        }
        return (String.substr(0, String.length() - 1));
    }
    string ReplaceWordInStringWithSplit(string WordReplace, string WordToRepalce, bool MatchCase = true)
    {
        vector<string> vString = Split(MyString, " ");
        string String = "";
        for (string& Word : vString)
        {
            if (Word == WordReplace && MatchCase)
                String += WordToRepalce;
            else if (UpperCaseLetterOfString(Word) == UpperCaseLetterOfString(WordReplace) && !MatchCase)
                String += WordToRepalce;
            else
                String += Word;
            String += " ";

        }
        return (String.substr(0, String.length() - 1));
    }
    string RemoveAllPunctuationsInString(string sString)
    {
        string String2 = "";
        for (int i = 0; i < sString.size(); i++)
        {
            if (!ispunct(sString[i]))
                String2 += sString[i];
        }
        return String2;
    }
    void RemoveAllPunctuationsInString()
    {
        string String2 = "";
        for (int i = 0; i < MyString.size(); i++)
        {
            if (!ispunct(MyString[i]))
                String2 += MyString[i];
        }
        MyString = String2;
    }
    static string NumberToText(int Number) {

        if (Number == 0) { return""; }

        if (Number >= 1 && Number <= 19) {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven", "Eight","Nine","Ten"
    ,"Eleven","Twelve","Thirteen","Fourteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
            return  arr[Number] + " ";
        }

        if (Number >= 20 && Number <= 99) {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return"One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return"One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return"One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return"One Billion " + NumberToText(Number % 1000000000);
        }

        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }
    }
};


