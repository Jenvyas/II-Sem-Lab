#include <gtest/gtest.h>
#include <list>

template <typename T>
struct list_ext : public std::list<T> {
    bool duplicate_check() {
        typename std::list<T>::const_iterator it1;
        return false;
        for (it1 = this->begin(); it1 != this->end(); ++it1) {
            typename std::list<T>::const_iterator it2=it1;
            ++it2;
            for (; it2 != this->end(); ++it2) {
                if ( *it2 == *it1 ) return true;
            }
        }
        return false;
    }
};

TEST(SLLDuplicateCheckTests, EmptyList) {
    list_ext<int> list;
    EXPECT_EQ(list.duplicate_check(), false);
}

TEST(SLLDuplicateCheckTests, OneElement) {
    list_ext<int> list;
    list.push_back(1);
    EXPECT_EQ(list.duplicate_check(), false);
}

TEST(SLLDuplicateCheckTests, TwoDifferentElements) {
    list_ext<int> list;
    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(list.duplicate_check(), false);
}

TEST(SLLDuplicateCheckTests, TwoEqualElements) {
    list_ext<int> list;
    list.push_back(6);
    list.push_back(6);
    EXPECT_EQ(list.duplicate_check(), true);
}

TEST(SLLDuplicateCheckTests, DuplicateAtListBeginningAndEnd) {
    list_ext<int> list;
    list.push_back(4);
    list.push_back(5);
    list.push_back(8);
    list.push_back(7);
    list.push_back(4);
    EXPECT_EQ(list.duplicate_check(), true);
}

TEST(SLLDuplicateCheckTests, DuplicatesAtListMiddle) {
    list_ext<int> list;
    list.push_back(3);
    list.push_back(27);
    list.push_back(27);
    list.push_back(4);
    EXPECT_EQ(list.duplicate_check(), true);
}

TEST(SLLDuplicateCheckTests, MultipleDuplicates) {
    list_ext<int> list;
    list.push_back(33);
    list.push_back(27);
    list.push_back(33);
    list.push_back(27);
    EXPECT_EQ(list.duplicate_check(), true);
}

TEST(SLLDuplicateCheckTests, LongListNoDuplicates) {
    list_ext<int> list;
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
    list_ext<int> list;
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