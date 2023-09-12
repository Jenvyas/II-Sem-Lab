#pragma once

#include <iostream>
#include <iomanip>
#include <string>

struct MenuOption {
    std::string option;
    std::string description;
};

//shows an individual option with a description of what it does
void show_option(std::string option, std::string description) {
    std::cout<<std::left<<std::setw(10)<<option<<description<<'\n'<<std::right;
}

//displays all available menu options
void show_options() {
    MenuOption main_menu[] = {
        {"show", "Displays all the dates stored in the file (removed dates are marked as red)"},
        {"add", "Add a date to the file"},
        {"remove", "Mark a date as removed"},
        {"delete", "Deletes all the dates marked as removed from the file"},
        {"help", "Shows all the available commands in the menu"},
        {"exit", "Exits the program"}
    };

    for(const auto& option: main_menu){
        show_option(option.option, option.description);
    }
}