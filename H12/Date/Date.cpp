#include "Date.h"

Date::Date(int year, int month, int date) {
    if (year < 1 || year > 9999)
        throw("The year of the date must be between 1 and 9999(inclusive)");

    if (month < 1 || month > 12)
        throw("The month of the date must be between 1 and 12(inclusive)");
        
    if ((month==2 && is_leap_year(year) && (date < 1 || date > 29)) || (date < 1 || date > MONTH_DAYS[month-1]))
        throw("Invalid day of the month provided");
    
    this->year = year;
    this->month = month;
    this->day = date;
}

int Date::get_year() {
    return this->year;
}

int Date::get_month() {
    return this->month;
}

int Date::get_day() {
    return this->day;
}

const std::string Date::MONTH_NAMES[12] = {"January", "February", "March", "April",
        "May", "June", "July", "August", "September", "October", "November", "December"};

const int Date::MONTH_DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool Date::operator==(const Date &d){
    return (d.year==this->year && d.month==this->month && d.day==this->day);
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << std::setw(4) << std::setfill('0') << date.year << '/' << std::setw(2) << date.month << '/' << std::setw(2) << date.day << std::setfill(' ');
    return os;
}

std::string Date::to_string() {
    std::ostringstream ss;
    ss << *this;
    return ss.str();
}

bool Date::is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}