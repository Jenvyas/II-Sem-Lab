#include "DateFile.h"

Date DateFile::BufferDate::to_date() {
    return Date(this->year, this->month, this->day);
}

DateFile::BufferDate::BufferDate() {
    year,month,day,status;
}

DateFile::BufferDate::BufferDate(Date& date) {
    this->year = date.get_year();
    this->month = date.get_month();
    this->day = date.get_day();
    this->status = 1;
}