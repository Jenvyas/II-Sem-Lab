#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <sys/stat.h>
#include <ios>
#include <limits>
#include "Date.h"
#include "Menu.h"

using namespace std;

void date_add(fstream& date_filestream, Date& added_date) {
    BufferDate date_buffer;
    bool entry_exists = false;

    while (date_filestream.read(reinterpret_cast<char *>(&date_buffer), sizeof(Date)) && !entry_exists)
        if (added_date == Date(date_buffer))
        {
            cout << "That date already exists\n";
            entry_exists = true;
            break;
        }

    date_filestream.clear();
    date_filestream.seekg(0, ios::beg);

    if (!entry_exists)
    {
        date_filestream.write(reinterpret_cast<char *>(&added_date), sizeof(Date));
        cout << added_date << " has been added\n";
    }
}

void add_mode(const string& date_file){
    fstream date_filestream;
    vector<Date> input_buffer;
    Date added_date;
    bool adding_dates = true;
    int year, month, day;

    date_filestream.open(date_file,ios::out | ios::in | ios::app | ios::binary);

    if (!date_filestream.is_open()) {
        cout << "File couldn't be opene\n";
        return;
    }

    cout << "Input Year, Month, Day, seperated by spaces.\n"
        << "(input -1 to finish)\n";

    while (adding_dates && !cin.eof())
    {
        if (cin >> year)
        {
            if (cin.eof() || year == -1) {
                date_filestream.close();
                break;
            }

            if (cin >> month >> day)
            {
                if (validate_date_input(added_date, year, month, day))
                    date_add(date_filestream, input_buffer, added_date);
            }
            else
            {
                cout << "Input error\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
        else
        {
            cout << "Input error\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    cin.clear();
    date_filestream.close();
}

void print_date(Date& date){
            cout
                << left << setw(8) << date.year
                << left << setw(8) << date.month
                << left << setw(4) << date.day
                << '\n';
}

void print_date(Date& date, string extra_param) {
            cout
                << left << setw(8) << date.year
                << left << setw(8) << date.month
                << left << setw(4) << date.day
                << left << setw(8) << extra_param << '\n';
}

void show_dates(const string& date_file){
    Date buffer_date;

    if (!date_filestream.is_open()) {
        cout<<"File couldn't be opened for reading\n";
        return;
    }

    cout
        << left << setw(8) << "Year"
        << left << setw(8) << "Month"
        << left << setw(4) << "Day"
        << '\n';
    while (date_filestream.read(reinterpret_cast<char *>(&buffer_date), sizeof(Date))) {
        if (buffer_date.status == 1) {
            print_date(buffer_date);
        }
    }

    date_filestream.close();
}

void show_remove_mode_dates(fstream& date_filestream){
    Date buffer_date;

    cout
    << left << setw(8) << "Year"
    << left << setw(8) << "Month"
    << left << setw(4) << "Day"
    << left << setw(8) << "Status"
    << '\n';
    
    while (date_filestream.read(reinterpret_cast<char *>(&buffer_date), sizeof(Date))) {
        if (buffer_date.status == 1) {
            print_date(buffer_date, "Active");
        }
        else
        {
            print_date(buffer_date,"Removed");
        }
    }

    date_filestream.clear();
    date_filestream.seekg(0, ios::beg);
};

void date_remove(fstream& date_filestream, Date& removed_date){
    Date date_buffer;
    bool entry_exists = false;
    int pos;

    while (!date_filestream.eof())
    {
        pos = date_filestream.tellg();

        date_filestream.read(reinterpret_cast<char*>(&date_buffer), sizeof(Date));
        if (date_filestream && date_buffer==removed_date)
        {
            entry_exists=true;
            break;
        }
    }

    date_filestream.clear();
    date_filestream.seekg(0, ios::beg);

    if (entry_exists){
        date_buffer.status=!date_buffer.status;
        date_filestream.seekp(pos);
        date_filestream.write(reinterpret_cast<char*>(&date_buffer), sizeof(Date));
        date_filestream.clear();
        date_filestream.seekp(0, ios::beg);
    }
    else cout<<"Entry not found\n";
}

void remove_mode(const string& date_file){
    fstream date_filestream;
    Date removed_date;
    bool removing_dates = true;
    int year, month, day;

    date_filestream.open(date_file, ios::in | ios::out | ios::binary);

    if(!date_filestream.is_open())
    {
        cout<<"File couldn't be opened\n";
        return;
    }

    show_remove_mode_dates(date_filestream);

    cout << "Input Year, Month, Day, seperated by spaces\n(if a Removed date gets entered its status will be changed to Active).\n"
        << "(input -1 to finish)\n";

    while (removing_dates && !cin.eof())
    {
        if (cin >> year)
        {
            if (cin.eof() || year == -1)
            {
                date_filestream.close();
                break;
            }

            if (cin >> month >> day)
            {
                if (validate_date_input(removed_date, year, month, day))
                {
                    date_remove(date_filestream, removed_date);
                }
            }
            else
            {
                cout << "Input error\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
        else
        {
            cout << "Input error\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    cin.clear();
    date_filestream.close();
}

void delete_marked_entries(const string& date_file){
    Date buffer_date;
    ofstream new_date_filestream;
    ifstream date_filestream;

    date_filestream.open(date_file, ios::in | ios::binary);

    if (!date_filestream.is_open())
    {
        cout<<"Failed to open file";
        return;
    }

    new_date_filestream.open("temp1.temp", ios::out | ios::app | ios::binary);

    if (!new_date_filestream.is_open())
    {
        cout<<"Failed to create temp file";
        return;
    }

    while(date_filestream.read(reinterpret_cast<char*>(&buffer_date),sizeof(Date)))
    {
        if (buffer_date.status)
        {
            new_date_filestream.write(reinterpret_cast<char*>(&buffer_date),sizeof(Date));
        }
    }

    new_date_filestream.close();
    date_filestream.close();

    remove(date_file.c_str());
    rename("temp1.temp", date_file.c_str());
}

void run(const string& file_name){
    show_options();
    string user_input;
    bool program_running = true;

    while(program_running){
        cin >> user_input;
        if (cin.eof()) break;
        if ( user_input=="show" ) show_dates(file_name);
        else if ( user_input=="add" ) add_mode(file_name);
        else if ( user_input=="remove" ) remove_mode(file_name);
        else if ( user_input=="delete" ) delete_marked_entries(file_name);
        else if ( user_input=="help" ) show_options();
        else if ( user_input=="exit" ) program_running = false;
        else cout<<"Unknown command: "<<user_input<<"\n\n"<<"To see a list of available commmands use: help\n";
    }
}

int main() {
    cout<<"Please enter the name of the date file you would like to open: ";

    string file_name;
    cin>>file_name;
    if (cin.eof()) return 0;

    struct stat stat_buffer;
    if (stat(file_name.c_str(), &stat_buffer)==0)
    {
        run(file_name);
    }
    else{
        cout<<"No file exists with that name\n"
        <<"Would you like to create a new file named: "<<file_name<<"\n"
        <<"(Y/N) - Yes or No\n";
        string user_answer;
        cin>>user_answer;
        if (cin.eof()) return 0;

        if (user_answer == "Y" || user_answer == "y")
        {
            ofstream new_file;
            new_file.open(file_name, ios::binary);
            if (new_file.is_open())
            {
                new_file.close();
                run(file_name);
            } else {
                cout<<"Couldn't create a new file";
            }
        } else {
            return 0;
        }
    }

    system("pause");
}