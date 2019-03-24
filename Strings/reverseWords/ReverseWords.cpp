//Build with the following command (requires google test library):
//g++ -Wall -Wextra -std=c++14 ReversWords.cpp -L/usr/local/lib -lgtest -lgtest_main -pthread

#include <algorithm>
#include <string>
#include <gtest/gtest.h>

using std::swap;
using std::string;

void reverseString(string& message, size_t start, size_t end){
    while (start < end) swap(message[start++], message[end--]);
}

void reverseWords(string& message)
{
    if (message.empty()) return;

    reverseString(message, 0, message.size()-1);

    size_t i = 0, j = message.find_first_of(' ', i);

    while (j != string::npos) {
        reverseString(message, i, j-1);
        i = j+1;
        j = message.find_first_of(' ', i);
    }
    reverseString(message, i, message.size()-1);
  }

// tests
TEST(ReverseWordsTest, OneWord) {
const string expected= "vault";
string actual= "vault";
        reverseWords(actual);
        ASSERT_EQ(actual, expected);
    }
TEST(ReverseWordsTest, TwoWords) {
const string expected= "cake thief";
string actual= "thief cake";
        reverseWords(actual);
        ASSERT_EQ(actual, expected);
    }
TEST(ReverseWordsTest, ThreeWords) {
const string expected= "get another one";
string actual= "one another get";
        reverseWords(actual);
        ASSERT_EQ(actual, expected);
    }
TEST(ReverseWordsTest, MultipleWordsSameLength) {
const string expected= "the cat ate the rat";
string actual= "rat the ate cat the";
        reverseWords(actual);
        ASSERT_EQ(actual, expected);
    }
TEST(ReverseWordsTest, MultipleWordsDifferentLengths) {
const string expected= "chocolate bundt cake is yummy";
string actual= "yummy is cake bundt chocolate";
        reverseWords(actual);
        ASSERT_EQ(actual, expected);
    }
TEST(ReverseWordsTest, EmptyString) {
        const string expected;
        string actual;
        reverseWords(actual);
        ASSERT_EQ(actual, expected);
    }

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
