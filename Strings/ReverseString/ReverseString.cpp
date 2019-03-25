//Build with the following command (requires google test library):
//g++ -Wall -Wextra -std=c++14 ReversString.cpp -L/usr/local/lib -lgtest -lgtest_main -pthread

#include <algorithm>
#include <string>
#include <gtest/gtest.h>

using std::string;
using std::swap;

void reverse(string& str)
{
  if (str.size() == 0) return;
  // reverse the input string in place
  size_t i = 0, j = str.size()-1;

  while (i < j) swap(str[i++], str[j--]);
}

TEST(ReverseStringTest, EmptyString) {
  const string expected;
  string actual;
  reverse(actual);
  ASSERT_EQ(actual,expected);
}
  TEST(ReverseStringTest, SingleCharacterString) {
    const string expected("A");
    string actual("A");
    reverse(actual);
    ASSERT_EQ(actual,expected);
  }
  TEST(ReverseStringTest, LongerString) {
    const string expected("EDCBA");
    string actual("ABCDE");
    reverse(actual);
    ASSERT_EQ(actual,expected);
  }

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}
