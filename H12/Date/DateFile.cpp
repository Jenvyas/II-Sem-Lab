#include "DateFile.h"

DateFile::DateFile(std::string file_name) {
    this->file_name = file_name;
}

int DateFile::add_date(Date& date) {
    std::fstream date_filestream(file_name, std::ios::out | std::ios::in | std::ios::app | std::ios::binary);

    if(!date_filestream.is_open())
        throw("File couldn't be opened.");

    BufferDate buffer_date;

    //goes through all dates in the file and checks if the date thats being passed to be added
    //is already present
    while (date_filestream.read(reinterpret_cast<char *>(&buffer_date), sizeof(BufferDate)))
        if (date == buffer_date.to_date()) {
            date_filestream.close();
            return 0;
        }

    //clears eof flags
    date_filestream.clear();
    
    //wrties a new date to the end of the file since the append flag is present
    BufferDate new_date(date);
    date_filestream.write(reinterpret_cast<char *>(&new_date), sizeof(BufferDate));
    date_filestream.close();
    return 1;
}

int DateFile::remove_date(Date &date) {
    std::fstream date_filestream(file_name, std::ios::in | std::ios::out | std::ios::binary);

    if(!date_filestream.is_open())
        throw("File couldn't be opened.");

    BufferDate buffer_date;
    int pos;

    //goes through all dates, if it finds a date that matches the input date, marks it as removed
    while (!date_filestream.eof()) {
        pos = date_filestream.tellg();  

        date_filestream.read(reinterpret_cast<char*>(&buffer_date), sizeof(BufferDate));
        if (date == buffer_date.to_date()) {
            date_filestream.clear();
            buffer_date.status=!buffer_date.status;
            date_filestream.seekp(pos);
            date_filestream.write(reinterpret_cast<char*>(&buffer_date), sizeof(BufferDate));
            date_filestream.close();
            return 1;
        }
    }

    date_filestream.close();
    return 0;
}

void DateFile::delete_removed_dates() {
    BufferDate buffer_date;
    //creates 2 filestreams, one for the original file and one for the temporary file
    std::ofstream new_date_filestream;
    std::ifstream date_filestream(file_name, std::ios::in | std::ios::binary);

    if (!date_filestream.is_open())
        throw("Failed to open file.");

    new_date_filestream.open("temp1.temp", std::ios::out | std::ios::app | std::ios::binary);

    if (!new_date_filestream.is_open())
        throw("Failed to create temp file.");

    //goes through all dates in the file, if the status of the date is 0, it doesn't get written
    //to the new file
    while(date_filestream.read(reinterpret_cast<char*>(&buffer_date),sizeof(BufferDate))) {
        if (buffer_date.status)
            new_date_filestream.write(reinterpret_cast<char*>(&buffer_date),sizeof(BufferDate));
    }

    new_date_filestream.close();
    date_filestream.close();

    //deletes the old file and renames the temp file to the filename
    remove(file_name.c_str());
    rename("temp1.temp", file_name.c_str());
}

std::ostream& operator<<(std::ostream& os, const DateFile& date_file) {
    std::ifstream date_filestream(date_file.file_name);

    if (!date_filestream.is_open())
        throw("File couldn't be opened for reading.");

    DateFile::BufferDate buffer_date;

    //goes through all dates and outputs them to a stream, removed dates are marked as red
    while (date_filestream.read(reinterpret_cast<char *>(&buffer_date), sizeof(DateFile::BufferDate))) {
        try {
            if (buffer_date.status) { os << buffer_date.to_date(); }
            else { os << "\u001b[31m" << buffer_date.to_date() << "\u001b[0m"; }
            os << '\n';
        } catch (const char* error) {
            os << error << '\n';
        }
    }

    date_filestream.close();

    return os;
}

std::string DateFile::to_string() {
    std::ostringstream ss;
    ss << *this;
    return ss.str();
}