#include <iostream>
#include <string>
#include <sys/stat.h>
#include <fstream>
#include "Date/Date.h"
#include "Date/DateFile.h"
#include "Menu.h"

using namespace std;


//Function to provide user interaction with the date file
void menu( DateFile date_file ) {
    string command;
    int year, month, day;

    show_options();

    //Handles user input, runs a while loop checking input while "exit" is not entered
    while ( command != "exit" ) {
        cin >> command;
        try {
            //shows the date file
            if( command == "show" ) {
                cout << date_file;
                //adds a date to the file if the input format is correct
            } else if ( command == "add" ) {
                cin >> year >> month >> day;

                Date date( year, month, day );

                int completed = date_file.add_date( date );

                cout << date << (completed ?  " has been added.\n" : " already exists.\n"); 
                //marks a given date in the file as removed
            } else if ( command == "remove" ) {
                cin >> year >> month >> day;

                Date date( year, month, day );

                int completed = date_file.remove_date( date );

                cout << date << (completed ?  " has been marked as removed.\n" : " does not exist.\n"); 
            } else if ( command == "delete" ) {
                //erases all removed dates from the file
                date_file.delete_removed_dates();
                cout<<"Marked dates have been deleted.\n";
            } else if ( command == "help") {
                //shows all the options again
                show_options();
            } else if ( command == "exit" ) {
                break;
            } else {
                cout<<"No such command was found\n";
            }
        } catch(const char* e) {
            cerr << e << '\n';
        }
    }
}

int main() {
    cout<<"Please enter the name of the date file you would like to open: ";

    string file_name;
    cin>>file_name;
    if ( cin.eof() ) return 0;

    //checks if the file exists or not
    struct stat stat_buffer;
    if ( stat(file_name.c_str(), &stat_buffer)==0 ) {
        DateFile date_file(file_name);
        menu(date_file);
    }
    //prompts to create a file if it does not exist
    else {
        cout<<"No file exists with that name\n"
        <<"Would you like to create a new file named: "<<file_name<<"\n"
        <<"(Y/N) - Yes or No\n";
        string user_answer;
        cin>>user_answer;
        if ( cin.eof() ) return 0;

        if ( user_answer == "Y" || user_answer == "y" ) {
            ofstream new_file;
            new_file.open( file_name, ios::binary );
            if ( new_file.is_open() ) {
                new_file.close();
                DateFile date_file( file_name );
                menu( date_file );
            } else {
                cout<<"Couldn't create a new file";
            }
        } else {
            return 0;
        }
    }

    system( "pause" );
}