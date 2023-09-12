#pragma once

#include "Date.h"
#include <string>
#include <sstream>
#include <fstream>

class DateFile {
private:
    std::string file_name;
    struct BufferDate {
        int year;
        int month;
        int day;
        int status;
        //converts a buffer date to a date
        Date to_date();
        BufferDate();
        //creates a bufferdate from a provided date
        BufferDate( Date& date );
    };
public:
    //initializes a datefile from a given file_name (does not check if the filename is valid)
    DateFile( std::string file_name );
    //adds a date to the file, returns 1 if operation was succesful, 0 if not
    int add_date( Date& date );
    //removes a date from the file, returns 1 if operation was succesful, 0 if not
    int remove_date( Date& date );
    //erases all date from the file that are marked as removed
    void delete_removed_dates();
    //outputs the date file to a stream
    friend std::ostream& operator<<( std::ostream& os, const DateFile& date_file );
    //converts file to a string
    std::string to_string();
};


