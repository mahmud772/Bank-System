#pragma once
#pragma warning(disable : 4996)
#include<iostream>
#include<vector>
#include<ctime>
#include"clsInputValidate.h";
using namespace std;
class clsDate
{
private:
    int _Day = 1;
    int _Month = 1;
    int _Year = 1900;
    vector<string> SplitEachWordInStringToVector(string String, string delim)
    {
        int pos = 0;
        string sWord;
        vector<string> vWords;
        while ((pos = String.find(delim)) != std::string::npos)
        {
            sWord = String.substr(0, pos);
            if (sWord != "")
                vWords.push_back(sWord);
            String.erase(0, pos + delim.length());
        }
        if (String != "")
            vWords.push_back(String);
        return vWords;
    }

public:
    clsDate()
    {
        time_t Time = time(0);
        tm* Now = localtime(&Time);
        _Year = Now->tm_year + 1900;
        _Month = Now->tm_mon + 1;
        _Day = Now->tm_mday;
    }
    clsDate(string Date)
    {
        vector<string> vDate = SplitEachWordInStringToVector(Date, "/");
        _Year = stoi(vDate[0]);
        _Month = stoi(vDate[1]);
        _Day = stoi(vDate[2]);
    }
    clsDate(int Year, int Month, int Day)
    {
        _Year = Year;
        _Month = Month;
        _Day = Day;
    }
    clsDate(int CountOfDays, int Year)
    {
        clsDate Date = GetDateFromDayOrderInYear(Year, CountOfDays);
        _Year = Date._Year;
        _Month = Date._Month;
        _Day = Date._Day;
    }
    void SetDay(int Day)
    {
        _Day = Day;
    }
    int GetDay()
    {
        return _Day;
    }
    __declspec(property(get = GetDay, put = SetDay)) int Day;
    void SetMonth(int Month)
    {
        _Month = Month;
    }
    int GetMonth()
    {
        return _Month;
    }
    __declspec(property(get = GetMonth, put = SetMonth)) int Month;
    void SetYear(int Year)
    {
        _Year = Year;
    }
    int GetYear()
    {
        return _Year;
    }
    __declspec(property(get = GetYear, put = SetYear)) int Year;
    void StringToDate(string String, string delim = "/")
    {
        vector<string> vWord = SplitEachWordInStringToVector(String, delim);
        if (vWord.size() == 3)
        {
            _Day = stoi(vWord[0]);
            _Month = stoi(vWord[1]);
            _Year = stoi(vWord[2]);
        }
    }
    static string DateToString(clsDate Date, string delim = "/")
    {
        return to_string(Date._Day) + delim + to_string(Date._Month) + delim + to_string(Date._Year);
    }
    string DateToString(string delim = "/")
    {
        return DateToString(*this);
    }
    static bool IsLeapYear(int Year)
    {
        return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
    }
    bool IsLeapYear()
    {
        return (_Year % 400 == 0 || (_Year % 4 == 0 && _Year % 100 != 0));
    }
    static int NumberOfDaysInYear(int Year)
    {
        return (IsLeapYear(Year) ? 366 : 365);
    }
    int NumberOfDaysInYear()
    {
        return (IsLeapYear() ? 366 : 365);
    }
    static int NumberOfHoursInYear(int Year)
    {
        return NumberOfDaysInYear(Year) * 24;
    }
    int NumberOfHoursInYear()
    {
        return NumberOfDaysInYear() * 24;
    }
    static int NumberOfMinutesInYear(int Year)
    {
        return NumberOfHoursInYear(Year) * 60;
    }
    int NumberOfMinutesInYear()
    {
        return NumberOfHoursInYear() * 60;
    }
    static int NumberOfSecondsInYear(int Year)
    {
        return NumberOfMinutesInYear(Year) * 60;
    }
    int NumberOfSecondsInYear()
    {
        return NumberOfMinutesInYear() * 60;
    }
    static void PrintNumberOf_DHMS_InYear(int Year)
    {
        cout << "Number Of Days    In Year : [" << Year << "] Is " << NumberOfDaysInYear(Year) << endl;
        cout << "Number Of Hours   In Year : [" << Year << "] Is " << NumberOfHoursInYear(Year) << endl;
        cout << "Number Of Minutes In Year : [" << Year << "] Is " << NumberOfMinutesInYear(Year) << endl;
        cout << "Number Of Seconds In Year : [" << Year << "] Is " << NumberOfSecondsInYear(Year) << endl;
    }
    void PrintNumberOf_DHMS_InYear()
    {
        cout << "Number Of Days    In Year : [" << _Year << "] Is " << NumberOfDaysInYear() << endl;
        cout << "Number Of Hours   In Year : [" << _Year << "] Is " << NumberOfHoursInYear() << endl;
        cout << "Number Of Minutes In Year : [" << _Year << "] Is " << NumberOfMinutesInYear() << endl;
        cout << "Number Of Seconds In Year : [" << _Year << "] Is " << NumberOfSecondsInYear() << endl;
    }
    static bool Is31DaysInMonth(int Month)
    {
        return((Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12));
    }
    bool Is31DaysInMonth()
    {
        return((_Month == 1 || _Month == 3 || _Month == 5 || _Month == 7 || _Month == 8 || _Month == 10 || _Month == 12));
    }
    static int NumberOfDaysInMonth(int Year, int Month)
    {
        if (Month > 12)
            return 0;
        return ((IsLeapYear(Year) && Month == 2) ? 29 : (Is31DaysInMonth(Month) ? 31 : (Month == 2 ? 28 : 30)));
    }
    int NumberOfDaysInMonth()
    {
        if (_Month > 12)
            return 0;
        return ((IsLeapYear() && _Month == 2) ? 29 : (Is31DaysInMonth() ? 31 : (_Month == 2 ? 28 : 30)));
    }
    static int NumberOfHoursInMonth(int Year, int Month)
    {
        return NumberOfDaysInMonth(Year, Month) * 24;
    }
    int NumberOfHoursInMonth()
    {
        return NumberOfDaysInMonth() * 24;
    }
    static int NumberOfMinutesInMonth(int Year, int Month)
    {
        return NumberOfHoursInMonth(Year, Month) * 60;
    }
    int NumberOfMinutesInMonth()
    {
        return NumberOfHoursInMonth() * 60;
    }
    static int NumberOfSecondsInMonth(int Year, int Month)
    {
        return NumberOfMinutesInMonth(Year, Month) * 60;
    }
    int NumberOfSecondsInMonth()
    {
        return NumberOfMinutesInMonth() * 60;
    }
    void ReadDate(string Message)
    {
        cout << Message << endl;
        _Year = clsInputValidate::ReadNumber("Enter a Year  : ", 1, 3000);
        _Month = clsInputValidate::ReadNumber("Enter a Month : ", 1, 12);
        _Day = clsInputValidate::ReadNumber("Enter a Day   : ", 1, NumberOfDaysInMonth());
    }
    void ReadDate()
    {
        _Year = clsInputValidate::ReadNumber("Enter a Year  : ", 1, 3000);
        _Month = clsInputValidate::ReadNumber("Enter a Month : ", 1, 12);
        _Day = clsInputValidate::ReadNumber("Enter a Day   : ", 1, NumberOfDaysInMonth());
    }
    void PrintNumberOf_DHMS_InMonth(int Year, int Month)
    {
        cout << "Number Of Days    In Month : [" << Month << "] Is " << NumberOfDaysInMonth(Year, Month) << endl;
        cout << "Number Of Hours   In Month : [" << Month << "] Is " << NumberOfHoursInMonth(Year, Month) << endl;
        cout << "Number Of Minutes In Month : [" << Month << "] Is " << NumberOfMinutesInMonth(Year, Month) << endl;
        cout << "Number Of Seconds In Month : [" << Month << "] Is " << NumberOfSecondsInMonth(Year, Month) << endl;
    }
    void PrintNumberOf_DHMS_InMonth()
    {
        cout << "Number Of Days    In Month : [" << _Month << "] Is " << NumberOfDaysInMonth() << endl;
        cout << "Number Of Hours   In Month : [" << _Month << "] Is " << NumberOfHoursInMonth() << endl;
        cout << "Number Of Minutes In Month : [" << _Month << "] Is " << NumberOfMinutesInMonth() << endl;
        cout << "Number Of Seconds In Month : [" << _Month << "] Is " << NumberOfSecondsInMonth() << endl;
    }
    static int CalculateDayOrder(int Year, int Month, int Day = 1)
    {
        int A = (14 - Month) / 12;
        int Y = Year - A;
        int M = Month + 12 * A - 2;
        int D = (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
        return D + 1;
    }
    int CalculateDayOrder()
    {
        int A = (14 - _Month) / 12;
        int Y = _Year - A;
        int M = _Month + 12 * A - 2;
        int D = (_Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
        return D + 1;
    }
    static string NameDay(int Day)
    {
        string Days[] = { "" , "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
        return Days[Day];
    }
    string NameDay()
    {
        string Days[] = { "" , "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
        return Days[_Day];
    }
    static string NameMonth(int Month)
    {
        string Months[] = { "","Jan" , "Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
        return Months[Month];
    }
    string NameMonth()
    {
        string Months[] = { "","Jan" , "Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
        return Months[_Month];
    }
    /*void PrintDate(stDate Date)
    {
        cout << "Date      : " << Date.Day << '/' << Date.Month << '/' << Date.Year << endl;
        cout << "Day Order : " << CalculateDayOrder(Date.Year, Date.Month, Date.Day) << endl;
        cout << "Day Name  : " << NameDay(CalculateDayOrder(Date.Year, Date.Month, Date.Day)) << endl;
    }*/
    static void PrintMonthCalendar(int Year, int Month)
    {
        cout << "\n  _______________" << NameMonth(Month) << "_______________\n";
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        int NumberDays = NumberOfDaysInMonth(Year, Month);
        int i = 1;
        int FirstDay = CalculateDayOrder(Year, Month);
        while (i <= (NumberDays + FirstDay))
        {
            if (FirstDay < i)
                printf("%5d", (i - FirstDay));
            else
                printf("     ");
            if (NameDay(CalculateDayOrder(Year, Month, (i - FirstDay))) == "Sat")
                cout << endl;
            i++;
        }
        cout << "\n  _________________________________\n";

    }
    void PrintMonthCalendar()
    {
        cout << "\n  _______________" << NameMonth() << "_______________\n";
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        int NumberDays = NumberOfDaysInMonth();
        int i = 1;
        int FirstDay = CalculateDayOrder();
        while (i <= (NumberDays + FirstDay))
        {
            if (FirstDay < i)
                printf("%5d", (i - FirstDay));
            else
                printf("     ");
            if (NameDay(CalculateDayOrder(_Year, _Month, (i - FirstDay))) == "Sat")
                cout << endl;
            i++;
        }
        cout << "\n  _________________________________\n";

    }
    static void PrintYearCalendar(int Year)
    {
        cout << "\n  =================================\n";
        cout << "\n\t  Calendar * " << Year << endl;
        cout << "\n  =================================\n";
        for (int i = 1; i <= 12; i++)
            PrintMonthCalendar(Year, i);
    }
    void PrintYearCalendar()
    {
        cout << "\n  =================================\n";
        cout << "\n\t  Calendar * " << _Year << endl;
        cout << "\n  =================================\n";
        for (int i = 1; i <= 12; i++)
            PrintMonthCalendar(_Year, i);
    }
    static int TotalDaysFromTheBeginningOfYear(int Year, int Month, int Day)
    {
        int TotalDays = 0;
        for (int i = 1; i < Month; i++)
            TotalDays += NumberOfDaysInMonth(Year, i);
        TotalDays += Day;
        return TotalDays;
    }
    int TotalDaysFromTheBeginningOfYear()
    {
        int TotalDays = 0;
        for (int i = 1; i < _Month; i++)
            TotalDays += NumberOfDaysInMonth(_Year, i);
        TotalDays += _Day;
        return TotalDays;
    }
    clsDate GetDateFromDayOrderInYear(short Year, short DateOrderInYear)
    {
        clsDate Date;
        short RemainingDays = DateOrderInYear;
        short MonthDays = 0;
        Date._Year = Year;
        Date._Month = 1;
        while (true)
        {
            MonthDays = NumberOfDaysInMonth(Year, Date._Month);
            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                Date._Month++;
            }
            else
            {
                Date._Day = RemainingDays;
                break;
            }
        }
        return Date;
    }
    clsDate HowManyDaysToAddToIt(clsDate Date, int NumberDays)
    {
        clsDate NewDate;
        short RemainingDays = NumberDays + TotalDaysFromTheBeginningOfYear(Date._Year, Date._Month, Date._Day);
        short YearDays = 0;
        NewDate._Year = Date._Year;
        while (true)
        {
            YearDays = NumberOfDaysInYear(NewDate._Year);
            if (RemainingDays > YearDays)
            {
                RemainingDays -= YearDays;
                NewDate._Year++;
            }
            else
            {
                break;
            }
        }
        NewDate = GetDateFromDayOrderInYear(NewDate._Year, RemainingDays);
        return NewDate;
    }
    static bool IsDate1BeforDate2(clsDate Date1, clsDate Date2)
    {
        if (Date1._Year < Date2._Year)
            return true;
        else if ((Date1._Year == Date2._Year) && (Date1._Month < Date2._Month))
            return true;
        else if ((Date1._Year == Date2._Year) && (Date1._Month == Date2._Month) && (Date1._Day < Date2._Day))
            return true;
        return false;
    }
    bool IsDate1BeforDate2(clsDate Date)
    {
        return (IsDate1BeforDate2(*this, Date));
    }
    static bool IsDate1EquelDate2(clsDate Date1, clsDate Date2)
    {
        return(Date1._Year == Date2._Year && Date1._Month == Date2._Month && Date1._Day == Date2._Day);
    }
    bool IsDate1EquelDate2(clsDate Date)
    {
        return(IsDate1EquelDate2(*this , Date));
    }
    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
    {
        return (!(IsDate1BeforDate2(Date1, Date2) || IsDate1EquelDate2(Date1, Date2)));
    }
    bool IsDate1AfterDate2(clsDate Date)
    {
        return (!(IsDate1BeforDate2(*this, Date) || IsDate1EquelDate2(*this, Date)));
    }
    static bool CheckLastDayInMonth(clsDate Date)
    {
        return (NumberOfDaysInMonth(Date._Year, Date._Month) == Date._Day);
    }
    bool CheckLastDayInMonth()
    {
        return (NumberOfDaysInMonth() == this -> _Day);
    }
    static bool CheckLastMonthInYear(clsDate Date)
    {
        return (Date._Month == 12);
    }
    bool CheckLastMonthInYear()
    {
        return (this -> _Month == 12);
    }
    void IncreaseDateByDay()
    {
        bool IsLastDayInMonth = CheckLastDayInMonth();
        bool IsLastMonthInYear = CheckLastMonthInYear();
        if (IsLastDayInMonth && IsLastMonthInYear)
        {
            _Day = 1;
            _Month = 1;
            _Year++;
            return;
        }
        else if (IsLastDayInMonth)
        {
            _Day = 1;
            _Month++;
            return;
        }
        _Day++;
        
    }
    static clsDate GetSystemDate()
    {
        clsDate Date;
        time_t t = time(0);
        tm* now = localtime(&t);
        Date._Year = now->tm_year + 1900;
        Date._Month = now->tm_mon + 1;
        Date._Day = now->tm_mday;
        return Date;
    }
    void IncreaseDateByDay( int NumberDays)
    {
        *this = HowManyDaysToAddToIt(*this, NumberDays);
    }
    void IncreaseDateByWeek()
    {
        *this = HowManyDaysToAddToIt(*this, 7);
    }
    void IncreaseDateByWeek(int NumberWeeks)
    {
        *this = HowManyDaysToAddToIt(*this, (7 * NumberWeeks));
    }
    void IncreaseDateByMonth()
    {
        *this = HowManyDaysToAddToIt(*this, NumberOfDaysInMonth());
    }
    void IncreaseDateByMonth(int NumberMonths)
    {
        while (NumberMonths >= 12)
        {
            this->_Year++;
            NumberMonths -= 12;
        }
        while (NumberMonths)
        {
            if (this->_Month == 12)
            {
                this->_Year++;
                this->_Month = 1;
            }
            else
            {
                this->_Month++;
            }
            NumberMonths--;
        }
        if (this->_Month == 2 && this->_Day >= 28)
            this->_Day = NumberOfDaysInMonth();
        
    }
    void IncreaseDateByYear()
    {
        this->_Year++;
        if (this->_Month == 2 && this->_Day >= 28)
            this->_Day = NumberOfDaysInMonth();
    }
    void IncreaseDateByYear( int NumberYears)
    {
        this->_Year += NumberYears;
        if (this->_Month == 2 && this->_Day >= 28)
            this->_Day = NumberOfDaysInMonth();
    }
    void IncreaseDateByDecade()
    {
        this->_Year += 10;
        if (this->_Month == 2 && this->_Day >= 28)
            this->_Day = NumberOfDaysInMonth();
    }
    void IncreaseDateByDecade(int NumberDecades)
    {
        this->_Year += (10 * NumberDecades);
        if (this->_Month == 2 && this->_Day >= 28)
            this->_Day = NumberOfDaysInMonth();
    }
    void IncreaseDateByCentury()
    {
        this->_Year += 100;
        if (this->_Month == 2 && this->_Day >= 28)
            this->_Day = NumberOfDaysInMonth();
    }
    void IncreaseDateByMillennium()
    {
        this->_Year += 1000;
        if (this->_Month == 2 && this->_Day >= 28)
            this->_Day = NumberOfDaysInMonth();
    }
    void PrintDateAfterIncreaseDate()
    {
        cout << "\nDate After:\n";
        // 01 - Adding day
        IncreaseDateByDay();
        cout << "\n01 - Adding day is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 02 - Adding 10 days
        IncreaseDateByDay(10);
        cout << "\n02 - Adding 10 days is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 03 - Adding week
        IncreaseDateByWeek();
        cout << "\n03 - Adding week is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 04 - Adding 10 weeks
        IncreaseDateByWeek(10);
        cout << "\n04 - Adding 10 weeks is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 05 - Adding month
        IncreaseDateByMonth();
        cout << "\n05 - Adding month is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 06 - Adding 5 months
        IncreaseDateByMonth(5);
        cout << "\n06 - Adding 5 months is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 07 - Adding year
        IncreaseDateByYear();
        cout << "\n07 - Adding year is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 08 - Adding 10 years
        IncreaseDateByYear(10);
        cout << "\n08 - Adding 10 years is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 9 - Adding decade
        IncreaseDateByDecade();
        cout << "\n09 - Adding decade is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 10 - Adding 10 decades
        IncreaseDateByDecade(10);
        cout << "\n10 - Adding 10 decades is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 11 - Adding century
        IncreaseDateByCentury();
        cout << "\n11 - Adding century is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 12 - Adding millennium
        IncreaseDateByMillennium();
        cout << "\n12 - Adding millennium is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
    }
    bool CheckFirstDayInMonth()
    {
        return (1 == _Day);
    }
    bool CheckFirstMonthInYear()
    {
        return (_Month == 1);
    }
    void DecreaseDateByDay()
    {
        bool IsFirstDayInMonth = CheckFirstDayInMonth();
        bool IsFirstMonthInYear = CheckFirstMonthInYear();
        if (IsFirstDayInMonth && IsFirstMonthInYear)
        {
            _Day = 31;
            _Month = 12;
            _Year--;
        }
        else if (IsFirstDayInMonth)
        {
            _Day = NumberOfDaysInMonth();
            _Month--;
        }
        _Day--;
    }
    void DecreaseDateByDay(int NumberDays)
    {
        while (NumberDays--)
            DecreaseDateByDay();
    }
    void DecreaseDateByWeek()
    {
        short NumberDays = 7;
        while (NumberDays--)
            DecreaseDateByDay();
    }
    void DecreaseDateByWeek(int NumberWeeks)
    {
        while (NumberWeeks--)
            DecreaseDateByWeek();
    }
    void DecreaseDateByMonth()
    {
        int NumberDays = NumberOfDaysInMonth();
        while (NumberDays--)
            DecreaseDateByDay();
    }
    void DecreaseDateByMonth(int NumberMonths)
    {
        while (NumberMonths--)
            DecreaseDateByMonth();
    }
    void DecreaseDateByYear()
    {
        _Year--;
        if (_Month == 2 && _Day >= 28)
            _Day = NumberOfDaysInMonth();
    }
    void DecreaseDateByYear(int NumberYears)
    {
        _Year -= NumberYears;
        if (_Month == 2 && _Day >= 28)
            _Day = NumberOfDaysInMonth();
    }
    void DecreaseDateByDecade()
    {
        _Year -= 10;
        if (_Month == 2 && _Day >= 28)
            _Day = NumberOfDaysInMonth();
    }
    void DecreaseDateByDecade(int NumberDecades)
    {
        _Year -= (10 * NumberDecades);
        if (_Month == 2 && _Day >= 28)
            _Day = NumberOfDaysInMonth();
    }
    void DecreaseDateByCentury()
    {
        _Year -= 100;
        if (_Month == 2 && _Day >= 28)
            _Day = NumberOfDaysInMonth();
    }
    void DecreaseDateByMillennium()
    {
        _Year -= 1000;
        if (_Month == 2 && _Day >= 28)
            _Day = NumberOfDaysInMonth();
    }
    int CalculateTheDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
    {
        if (IsDate1BeforDate2(Date2, *this))
        {
            swap(*this, Date2);
        }
        int Days = 0;
        while (this->_Year < Date2._Year)
        {
            Days += NumberOfDaysInYear(this->_Year);
            this->_Year++;
        }
        Days += (TotalDaysFromTheBeginningOfYear(Date2._Year, Date2._Month, Date2._Day) - TotalDaysFromTheBeginningOfYear(this->_Year, this->_Month, this->_Day));
        if (IncludeEndDay)
            ++Days;
        return  Days;
    }
    static int CalculateTheDifferenceInDays(clsDate Date1 , clsDate Date2, bool IncludeEndDay = false)
    {
        if (IsDate1BeforDate2(Date2, Date1))
        {
            swap(Date1, Date2);
        }
        int Days = 0;
        while (Date1._Year < Date2._Year)
        {
            Days += NumberOfDaysInYear(Date1._Year);
            Date1._Year++;
        }
        Days += (TotalDaysFromTheBeginningOfYear(Date2._Year, Date2._Month, Date2._Day) - TotalDaysFromTheBeginningOfYear(Date1._Year, Date1._Month, Date1._Day));
        if (IncludeEndDay)
            ++Days;
        return  Days;
    }
    void PrintDateAfterDecreaseDate()
    {
        cout << "\nDate Delete:\n";
        // 01 - Delete day
        DecreaseDateByDay();
        cout << "\n01 - Delete day is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 02 - Delete 10 days
        DecreaseDateByDay(10);
        cout << "\n02 - Delete 10 days is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 03 - Delete week
        DecreaseDateByWeek();
        cout << "\n03 - Delete week is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 04 - Delete 10 weeks
        DecreaseDateByWeek(10);
        cout << "\n04 - Delete 10 weeks is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 05 - Delete month
        DecreaseDateByMonth();
        cout << "\n05 - Delete month is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 06 - Delete 5 months
        DecreaseDateByMonth(5);
        cout << "\n06 - Delete 5 months is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 07 - Delete year
        DecreaseDateByYear();
        cout << "\n07 - Delete year is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 08 - Delete 10 years
        DecreaseDateByYear(10);
        cout << "\n08 - Delete 10 years is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 9 - Delete decade
        DecreaseDateByDecade();
        cout << "\n09 - Delete decade is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 10 - Delete 10 decades
        DecreaseDateByDecade(10);
        cout << "\n10 - Delete 10 decades is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 11 - Delete century
        DecreaseDateByCentury();
        cout << "\n11 - Delete century is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
        // 12 - Delete millennium
        DecreaseDateByMillennium();
        cout << "\n12 - Delete millennium is: "
            << this->_Day << "/" << this->_Month << "/" << this->_Year;
    }
    void PrintToday()
    {
        cout << "Today is " << NameDay(CalculateDayOrder());
        cout << " , " << _Day << '/' << _Month << '/' << _Year << endl;
    }
    void PrintToday(string Message)
    {
        cout << Message << NameDay(CalculateDayOrder());
        cout << " , " << _Day << '/' << _Month << '/' << _Year << endl;
    }
    bool IsEndOfWeek()
    {
        return (CalculateDayOrder() == 7);
    }
    void PrintIsEndOfWeek()
    {
        cout << "Is It End Of Week ?\n";
        if (IsEndOfWeek())
            cout << "Yes It Is End Of Week.\n";
        else
            cout << "No Not End Of Week.\n";
    }
    bool IsWeekend()
    {
        int DayInWeek = CalculateDayOrder();
        return (DayInWeek == 7 || DayInWeek == 6);
    }
    void PrintIsWeekend()
    {
        cout << "Is It Weekend ?\n";
        if (IsWeekend())
            cout << "Yes Is It Weekend.\n";
        else
            cout << "No Not Weekend.\n";
    }
    bool IsBusinessDay()
    {
        return (!IsWeekend());
    }
    void PrintIsBusinessDay()
    {
        cout << "Is It Business Day ?\n";
        if (IsBusinessDay())
            cout << "Yes Is It Business Day.\n";
        else
            cout << "No Not Business Day.\n";
    }
    int DaysUntilEndOfWeek()
    {
        return (7 - CalculateDayOrder());
    }
    int DaysUntilEndOfMonth()
    {
        return (NumberOfDaysInMonth() - _Day);
    }
    int DaysUntilEndOfYear()
    {
        return (NumberOfDaysInYear() - TotalDaysFromTheBeginningOfYear() + 1);
    }
    void PrintDaysUntilEndOfWMY()
    {
        cout << "Days Until End Of Week  : " << DaysUntilEndOfWeek() << " Day(s)." << endl;
        cout << "Days Until End Of Month : " << DaysUntilEndOfMonth() << " Day(s)." << endl;
        cout << "Days Until End Of Year  : " << DaysUntilEndOfYear() << " Day(s)." << endl;
    }
    int CountVacationDays(clsDate Date2)
    {
        int Days = 0;
        while (!IsDate1EquelDate2(*this, Date2))
        {
            if (IsBusinessDay())
                Days++;
            IncreaseDateByDay();
        }
        return Days;
    }
    void PrintDate()
    {
        cout << DateToString() ;
    }
    static clsDate ReturnDateAfterVacation(clsDate Date, int VacationDays)
    {
        short WeekEndCounter = 0;
        clsDate Date2;
        Date2.IncreaseDateByDay(VacationDays);
        while (Date.IsWeekend())
        {
            Date.IncreaseDateByDay();
        }
        for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
        {
            if (Date.IsWeekend())
                WeekEndCounter++;
            Date.IncreaseDateByDay();
        }
        while (Date.IsWeekend())
        {
            Date.IncreaseDateByDay();
        }
        return Date;
    }
    void ReturnDateAfterVacation(int VacationDays)
    {
        short WeekEndCounter = 0;
        while (IsWeekend())
        {
            IncreaseDateByDay();
        }
        for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
        {
            if (IsWeekend())
                WeekEndCounter++;
            IncreaseDateByDay();
        }
        while (IsWeekend())
        {
            IncreaseDateByDay();
        }
    }
    static bool IsDateBetween(clsDate Date, clsDate Date1, clsDate Date2)
    {
        return ((Date1.IsDate1BeforDate2(Date) && Date2.IsDate1AfterDate2(Date)) ||
            (Date2.IsDate1BeforDate2(Date) && Date1.IsDate1AfterDate2(Date)));
    }
    static bool IsValideDate(clsDate Date)
    {
        return !(Date.Day > Date.NumberOfDaysInMonth() || Date.GetMonth() > 12 || Date.GetYear() < 1);
    }
    static string SystemDateYMDHMS()
    {
        time_t Time = time(0);
        tm* Now = localtime(&Time);
        string Date = "";
        Date += to_string(Now->tm_year + 1900) += "/";
        Date += to_string(Now->tm_mon + 1) += "/";
        Date += to_string(Now->tm_mday) ;
        Date += " - ";
        Date += to_string(Now->tm_hour) += ":";
        Date += to_string(Now->tm_min) += ":";
        Date += to_string(Now->tm_sec);
        return Date;
    }

};

