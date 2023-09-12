#include <gtest/gtest.h>
#include "SinglyLinkedList.h"

TEST(SLLDuplicateCheckTests, EmptyList) {
    SinglyLinkedList<int> list;
    EXPECT_EQ(list.duplicate_check(), false);
}

TEST(SLLDuplicateCheckTests, OneElement) {
    SinglyLinkedList<int> list;
    list.push_back(1);
    EXPECT_EQ(list.duplicate_check(), false);
}

TEST(SLLDuplicateCheckTests, TwoDifferentElements) {
    SinglyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(list.duplicate_check(), false);
}

TEST(SLLDuplicateCheckTests, TwoEqualElements) {
    SinglyLinkedList<int> list;
    list.push_back(6);
    list.push_back(6);
    EXPECT_EQ(list.duplicate_check(), true);
}

TEST(SLLDuplicateCheckTests, DuplicateAtListBeginningAndEnd) {
    SinglyLinkedList<int> list;
    list.push_back(4);
    list.push_back(5);
    list.push_back(8);
    list.push_back(7);
    list.push_back(4);
    EXPECT_EQ(list.duplicate_check(), true);
}

TEST(SLLDuplicateCheckTests, DuplicatesAtListMiddle) {
    SinglyLinkedList<int> list;
    list.push_back(3);
    list.push_back(27);
    list.push_back(27);
    list.push_back(4);
    EXPECT_EQ(list.duplicate_check(), true);
}

TEST(SLLDuplicateCheckTests, MultipleDuplicates) {
    SinglyLinkedList<int> list;
    list.push_back(33);
    list.push_back(27);
    list.push_back(33);
    list.push_back(27);
    EXPECT_EQ(list.duplicate_check(), true);
}

TEST(SLLDuplicateCheckTests, LongListNoDuplicates) {
    SinglyLinkedList<int> list;
    list.push_back(3);
    list.push_back(26);
    list.push_back(27);
    list.push_back(4);
    list.push_back(2);
    list.push_back(887);
    list.push_back(2341);
    list.push_back(13);
    list.push_back(15);
    EXPECT_EQ(list.duplicate_check(), false);
}

TEST(SLLDuplicateCheckTests, LongListSomeDuplicates) {
    SinglyLinkedList<int> list;
    list.push_back(3);
    list.push_back(26);
    list.push_back(13);
    list.push_back(4);
    list.push_back(2341);
    list.push_back(887);
    list.push_back(2341);
    list.push_back(13);
    list.push_back(15);
    EXPECT_EQ(list.duplicate_check(), true);
}

