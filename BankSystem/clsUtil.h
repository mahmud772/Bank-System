#pragma once
#include<iostream>
#include<cstdlib>
using namespace std;
class clsUtil
{
private:
    
public:
    static void Srand()
    {
        srand((unsigned)time(NULL));
    }
    enum enRandomChar
    {
        SmallLetter = 1,
        CapitalLetter = 2,
        SpecialCharacter = 3,
        Digit = 4,
        Mix = 5
    };
    static int RandomNumber(int From, int To)
    {
        int RandomNumber = rand() % (To - From + 1) + From;
        return RandomNumber;
    }
    static char RandomChar(enRandomChar RandomVa)
    {
        switch (RandomVa)
        {
        case enRandomChar::CapitalLetter:
            return char(RandomNumber(65, 90));

        case enRandomChar::SmallLetter:
            return char(RandomNumber(97, 122));

        case enRandomChar::SpecialCharacter:
            return char(RandomNumber(33, 47));

        case enRandomChar::Digit:
            return char(RandomNumber(48, 57));
        }
        return char(RandomNumber(33, 122));
    }
    static string GenerateRandomWord(int Length )
    {
        string Word = "";
        while (Length--)
            Word += RandomChar(enRandomChar(RandomNumber(1, 2)));
        return Word;
    }
    static string GenerateRandomKey( enRandomChar TypeOfChar)
    {
        int NumberOfSyllables = 4;
        int NumberOfLetter = 4;
        string RandomKey = "";
        for (int i = 0; i < NumberOfSyllables; i++) {
            for (int j = 0; j < NumberOfLetter; j++)
                RandomKey += RandomChar(TypeOfChar);
            if (i < NumberOfSyllables - 1)
                RandomKey += '-';
        }
        return RandomKey;
    }
    static void GenerateRandomKey(int NumberOfKey , enRandomChar TypeOfChar)
    {
        while (NumberOfKey--)
            cout << GenerateRandomKey(TypeOfChar) << endl;
    }
    static void Swap(int &FirstNumber, int &SecondNumber)
    {
        int Temp;
        Temp = FirstNumber;
        FirstNumber = SecondNumber;
        SecondNumber = Temp;
    }
    static void Swap(float& FirstNumber, float& SecondNumber)
    {
        float Temp;
        Temp = FirstNumber;
        FirstNumber = SecondNumber;
        SecondNumber = Temp;
    }
    static void Swap(double& FirstNumber, double& SecondNumber)
    {
        double Temp;
        Temp = FirstNumber;
        FirstNumber = SecondNumber;
        SecondNumber = Temp;
    }
    static void Swap(char& FirstChar, char& SecondChar)
    {
        char Temp;
        Temp = FirstChar;
        FirstChar = SecondChar;
        SecondChar = Temp;
    }
    static void Swap(string& FirstString, string& SecondString)
    {
        string Temp;
        Temp = FirstString;
        FirstString = SecondString;
        SecondString = Temp;
    }
    static void ShuffleArray(int Array[] , int Size)
    {
        for (int i = 0; i < Size/2; i++)
            Swap(Array[RandomNumber(0,Size-1)], Array[RandomNumber(0, Size - 1)]);
    }
    static void FillArrayWithRandomValue(int Array[], int Size, int From, int To)
    {
        for (int i = 0; i < Size; i++)
            Array[i] = RandomNumber(From, To);
    }
    static void FillArrayWithRandomValue(string Array[], int Size, int LengthWord = 0)
    {
        for (int i = 0; i < Size; i++)
            if(LengthWord > 0)
                Array[i] = GenerateRandomWord(LengthWord);
            else
                Array[i] = GenerateRandomWord(RandomNumber(4,8));
    }
    static void FillArrayWithRandomValue(char Array[], int Size, enRandomChar RandomVa = Mix)
    {
        for (int i = 0; i < Size; i++)
            Array[i] = RandomChar(RandomVa);
    }
    static string Tabs(int Number = 1)
    {
        string T = "";
        while (Number--)
            T+= '\t';
        return T;
    }
    static string EncryptText(string Text , int EncryptionKey)
    {
        for(int i=0;i<Text.size();i++)
            Text[i]+=EncryptionKey;
        return Text;
    }
    static string DecryptText(string Text, int EncryptionKey)
    {
        for(int i=0;i<Text.size();i++)
            Text[i]-=EncryptionKey;
        return Text;
    }
};

