/*************************************************************************************************************** 
This C++ program calculates the total time a user has lived based on their birth date and time. It prompts the user for their birth month, day, year, hour, minute, second, and AM/PM indicator, then retrieves the current system date and time. It calculates:

Total days, weeks, months, years, hours, minutes, and seconds lived

The exact age in years, months, days, hours, minutes, and seconds
The program manually calculates leap years and the number of days in each month, and accounts for date and time differences. It uses helper functions like calculatetotaldays and Currenttotalday for modularity.


****************************************************************************************************************/

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

// Function declarations
int calculatetotaldays(int dayy,int monthh,int yearr,int hourr,int curryear,int currmonth,int currday,int currhour);
int Currenttotalday(int MONTH, int YEAR);

int main(){
    int Year, Month, Day, dayOfWeek, Hour, Minute, Second, amORpm;

    // Ask the user for their birth date and time
    cout << "Welcome to the Age Calculator. Kindly enter your birth date to determine your age." << endl;
    cout << "Enter the month (1-12): ";
    cin >> Month;
    cout << "Enter the day (1-31): ";
    cin >> Day;
    cout << "Enter the year (e.g., 2025): ";
    cin >> Year;
    cout << "Enter the day of the week (1 for Sunday, 2 for Monday, ..., 7 for Saturday): ";
    cin >> dayOfWeek;
    cout << "Enter the hour (1-12): ";
    cin >> Hour;
    cout << "Enter the minute (0-59): ";
    cin >> Minute;
    cout << "Enter the second (0-59): ";
    cin >> Second;
    cout << "Enter AM (1) or PM (2): ";
    cin >> amORpm;

    // Get the current time from the system
    time_t currentime = time(nullptr);
    tm* localTime = localtime(&currentime);

    // Extract current date and time components
    int currentYear = localTime->tm_year + 1900;
    int currentMonth = localTime->tm_mon + 1;
    int currentDay = localTime->tm_mday;
    int currentDayofweek = localTime->tm_wday;
    int currentHour = localTime->tm_hour;
    int currentMinute = localTime->tm_min;
    int currentSecond = localTime->tm_sec;

    // Calculate total full days lived
    int Totaldays = calculatetotaldays(Day, Month, Year, Hour, currentYear, currentMonth, currentDay, currentHour);

    // Variables for total values
    int Totalyear, Totalmonth, Totalweeks, Totalhour, Totalminute, Totalsecond;

    // Calculate total full years lived
    Totalyear = Totaldays / 365;

    // Calculate total full months lived
    if (currentMonth < Month)
        Totalmonth = Totalyear * 12 + (12 + (currentMonth - Month));
    else
        Totalmonth = Totalyear * 12 + (currentMonth - Month);

    // Adjust for partial months
    if (currentDay < Day) {
        Totalmonth -= 1;
    }

    // Calculate total full weeks lived
    Totalweeks = Totaldays / 7;

    // Calculate total full hours lived based on AM/PM
    if (amORpm == 2) {
        Totalhour = (Totaldays * 24) + Hour;
    }
    if (amORpm == 1) {
        Totalhour = (Totaldays * 24) - Hour;
    }

    // Calculate total full minutes lived
    Totalminute = (Totalhour * 60) - Minute;

    // Calculate total full seconds lived
    Totalsecond = Totalminute * 60;

    // Calculate the exact age component-wise
    int exactyear = currentYear - Year;
    int exactmonth = currentMonth - Month;
    int exactday = currentDay - Day;
    int exacthour = currentHour - Hour;
    int exactminute = currentMinute - Minute;
    int exactsecond = currentSecond - Second;

    // Handle negative values by borrowing
    if (exactsecond < 0) {
        exactsecond += 60;
        exactminute--;
    }
    if (exactminute < 0) {
        exactminute += 60;
        exacthour--;
    }
    if (exacthour < 0) {
        exacthour += 24;
        exactday--;
    }
    if (exactday < 0) {
        exactmonth--;
        int prevMonth = (currentMonth == 1) ? 12 : currentMonth - 1;
        int daysInPrevMonth = (prevMonth == 2) ? 28 : ((prevMonth == 4 || prevMonth == 6 || prevMonth == 9 || prevMonth == 11) ? 30 : 31);
        exactday += daysInPrevMonth;
    }
    if (exactmonth < 0) {
        exactmonth += 12;
        exactyear--;
    }

    // Display the results
    cout << left << setw(80) << "--------------------------------------------------------------------------------" << endl;
    cout << left << setw(80) << "|                    CALCULATE HOW MANY DAYS YOU LIVED                         |" << endl;
    cout << left << setw(80) << "--------------------------------------------------------------------------------" << endl;
    cout << "You were born in " << Month << "/" << Day << "/" << Year << " at " << Hour << ":" << Minute << ":" << Second << endl;
    cout << "Total full years lived: " << Totalyear << endl
         << "Total full months lived: " << Totalmonth << endl
         << "Total full weeks lived: " << Totalweeks << endl
         << "Total full days lived: " << Totaldays << endl
         << "Total full hours lived: " << Totalhour << endl
         << "Total full minutes lived: " << Totalminute << endl
         << "Total full seconds lived: " << Totalsecond << endl;
    cout << "In total age you have lived is " << exactyear << " year "
         << exactmonth << " months " << exactday << " days "
         << exacthour << " hours " << exactminute << " minute and "
         << exactsecond << " seconds ";

    return 0;
}

// Calculates total number of days from birth to current date
int calculatetotaldays(int dayy , int monthh , int yearr ,int hourr, int curryear , int currmonth , int currday ,int currhour) {
    int totaldays = 0;

    for (int i = yearr; i <= curryear; i++) {
        if (i == curryear) {
            // Last year - only go until the current month and day
            while (monthh < currmonth) {
                for (int j = dayy; j <= Currenttotalday(monthh, i); j++) {
                    totaldays++;
                }
                dayy = 1;
                monthh++;
            }
            for (int k = dayy; k <= currday; k++) {
                totaldays++;
            }
        } else {
            // Full years in between
            for (int m = monthh; m <= 12; m++) {
                for (int j = dayy; j <= Currenttotalday(m, i); j++) {
                    totaldays++;
                }
                dayy = 1;
            }
            monthh = 1;
        }
    }

    // Adjust if the current hour is before birth hour (not a full day yet)
    if (currhour < hourr) {
        totaldays = totaldays - 1;
    }

    return totaldays;
}

// Returns number of days in a given month and year (leap year handled)
int Currenttotalday(int MONTH, int YEAR) {
    if (MONTH == 1 || MONTH == 3 || MONTH == 5 || MONTH == 7 || MONTH == 8 || MONTH == 10 || MONTH == 12) {
        return 31;
    } else if (MONTH == 2) {
        if (YEAR % 4 == 0) {
            if (YEAR % 100 == 0) {
                if (YEAR % 400 == 0) return 29;
                else return 28;
            } else return 29;
        } else return 28;
    } else if (MONTH == 4 || MONTH == 6 || MONTH == 9 || MONTH == 11) {
        return 30;
    }
    return 0;  // For invalid month
}
