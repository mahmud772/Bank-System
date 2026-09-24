#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include"clsInputValidate.h";
#include"clsDate.h";
using namespace std;
class clsPeriod
{
private:
	clsDate StartDate;
	clsDate EndDate;
public:
    void ReadPeriod(string Message)
    {
        cout << Message << endl;
        cout << "\nEnter Start Date :- \n";
        StartDate.ReadDate();
        cout << "\nEnter End   Date :- \n";
        EndDate.ReadDate();
    }
    void ReadPeriod()
    {
        cout << "Enter Period : " << endl;
        cout << "\nEnter Start Date :- \n";
        StartDate.ReadDate();
        cout << "\nEnter End   Date :- \n";
        EndDate.ReadDate();
    }
    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {
        return (!(clsDate::IsDate1AfterDate2(Period1.StartDate, Period2.EndDate) || clsDate::IsDate1BeforDate2(Period1.EndDate, Period2.StartDate)));
    }
    bool IsOverlapPeriods(clsPeriod Period2)
    {
        return (!(clsDate::IsDate1AfterDate2(StartDate, Period2.EndDate) || clsDate::IsDate1BeforDate2(EndDate, Period2.StartDate)));
    }
    static void PrintIsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {
        if (IsOverlapPeriods(Period1, Period2))
            cout << "Yes , Is Overlap\n";
        else
            cout << "No , Is Not Overlap\n";
    }
    void PrintIsOverlapPeriods(clsPeriod Period2)
    {
        if (IsOverlapPeriods(*this ,Period2))
            cout << "Yes , Is Overlap\n";
        else
            cout << "No , Is Not Overlap\n";
    }
    static int CalculatePeriodLengthInDays(clsPeriod Period, bool InCludeEndDay = false)
    {
        return clsDate::CalculateTheDifferenceInDays(Period.StartDate, Period.EndDate) + InCludeEndDay;
    }
    int CalculatePeriodLengthInDays(bool InCludeEndDay = false)
    {
        return clsDate::CalculateTheDifferenceInDays(StartDate, EndDate) + InCludeEndDay;
    }
    static bool IsDateInPeriod(clsPeriod Period, clsDate Date)
    {
        return (!(clsDate::IsDate1AfterDate2(Date, Period.EndDate) || clsDate::IsDate1BeforDate2(Date, Period.StartDate)));
    }
    bool IsDateInPeriod(clsDate Date)
    {
        return (!(clsDate::IsDate1AfterDate2(Date, EndDate) || clsDate::IsDate1BeforDate2(Date, StartDate)));
    }
    static int CountOverlapDaysInTowPeriod(clsPeriod Period1, clsPeriod Period2)
    {
        clsPeriod TempPeriod;
        TempPeriod.StartDate = clsDate::IsDate1AfterDate2(Period1.StartDate, Period2.StartDate) ? Period1.StartDate : Period2.StartDate;
        TempPeriod.EndDate = clsDate::IsDate1BeforDate2(Period1.EndDate, Period2.EndDate) ? Period1.EndDate : Period2.EndDate;
        if (!IsOverlapPeriods(Period1, Period2))
            return 0;
        return CalculatePeriodLengthInDays(TempPeriod);
    }
    int CountOverlapDaysInTowPeriod(clsPeriod Period2)
    {
        clsPeriod TempPeriod;
        TempPeriod.StartDate = clsDate::IsDate1AfterDate2(StartDate, Period2.StartDate) ? StartDate : Period2.StartDate;
        TempPeriod.EndDate = clsDate::IsDate1BeforDate2(EndDate, Period2.EndDate) ? EndDate : Period2.EndDate;
        if (!IsOverlapPeriods(*this, Period2))
            return 0;
        return CalculatePeriodLengthInDays(TempPeriod);
    }
};

