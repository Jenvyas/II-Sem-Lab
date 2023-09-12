#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date( int year, int month, int date );
    int get_year();
    int get_month();
    int get_day();
    bool operator==( const Date& d );
    //outputs the date to a stream
    friend std::ostream& operator<<( std::ostream& os, const Date& date );
    //converts date to a string
    std::string to_string();
    //checks if a given year is a leap year
    static bool is_leap_year( int year );
    //an array of all month names
    static const std::string MONTH_NAMES[12];
    //an array of all dates in a month
    static const int MONTH_DAYS[12];
};