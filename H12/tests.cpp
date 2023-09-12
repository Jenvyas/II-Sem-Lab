#include <gtest/gtest.h>
#include "Date/Date.h"
#include "Date/DateFile.h"

TEST(DateFileTests, AddOneDateToEmptyFile) {
    DateFile file = DateFile("./test_files/AddOneDateToEmptyFile.bin");
    Date new_date = {2003,1,16};
    file.add_date(new_date);
    EXPECT_EQ(file.to_string(), DateFile("./test_files/AddOneDateToEmptyFileExpected.bin").to_string());
    remove("./test_files/AddOneDateToEmptyFile.bin");
}

TEST(DateFileTests, AddOneThenRemoveFromEmptyFile) {
    DateFile file = DateFile("./test_files/AddOneThenRemoveFromEmptyFile.bin");
    Date new_date = {2003,1,16};
    file.add_date(new_date);
    file.remove_date(new_date);
    EXPECT_EQ(file.to_string(), DateFile("./test_files/AddOneThenRemoveFromEmptyFileExpected.bin").to_string());
    remove("./test_files/AddOneThenRemoveFromEmptyFile.bin");
}

TEST(DateFileTests, AddThreeThenRemoveMiddle) {
    DateFile file = DateFile("./test_files/AddThreeThenRemoveMiddle.bin");
    Date new_date = {2003,1,16};
    file.add_date(new_date);

    new_date = {192, 1, 2};
    file.add_date(new_date);

    new_date ={2005, 3, 5};
    file.add_date(new_date);

    new_date = {192, 1, 2};
    file.remove_date(new_date);

    EXPECT_EQ(file.to_string(), DateFile("./test_files/AddThreeThenRemoveMiddleExpected.bin").to_string());
    remove("./test_files/AddThreeThenRemoveMiddle.bin");
}

TEST(DateFileTests, AddThreeThenRemoveMiddleAndDelete) {
    DateFile file = DateFile("./test_files/AddThreeThenRemoveMiddleAndDelete.bin");
    Date new_date = {2003,1,16};
    file.add_date(new_date);

    new_date = {192, 1, 2};
    file.add_date(new_date);

    new_date ={2005, 3, 5};
    file.add_date(new_date);

    new_date = {192, 1, 2};
    file.remove_date(new_date);

    file.delete_removed_dates();
    
    EXPECT_EQ(file.to_string(), DateFile("./test_files/AddThreeThenRemoveMiddleAndDeleteExpected.bin").to_string());
    remove("./test_files/AddThreeThenRemoveMiddleAndDelete.bin");
}

TEST(DateFileTests, DeleteMultiple) {
    DateFile file = DateFile("./test_files/DeleteMultiple.bin");

    //adding dates

    Date new_date = {2003,1,16};
    file.add_date(new_date);

    new_date = {192, 1, 2};
    file.add_date(new_date);

    new_date ={2005, 3, 5};
    file.add_date(new_date);

    new_date ={2009, 12, 1};
    file.add_date(new_date);

    new_date ={2023, 4, 18};
    file.add_date(new_date);

    //removing dates

    new_date = {192, 1, 2};
    file.remove_date(new_date);

    new_date = {2009, 12, 1};
    file.remove_date(new_date);

    file.delete_removed_dates();
    
    EXPECT_EQ(file.to_string(), DateFile("./test_files/DeleteMultipleExpected.bin").to_string());
    remove("./test_files/DeleteMultiple.bin");
}



