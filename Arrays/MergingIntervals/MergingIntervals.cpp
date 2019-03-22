//Build with the following command (requires google test library):
//g++ -Wall -Wextra -std=c++14 MergingIntervals.cpp -L/usr/local/lib -lgtest -lgtest_main -pthread

#include <set>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

using std::vector;
using std::max;
using std::min;
using std::set;

class Meeting
{
 private:
  unsigned int mStartTime;
  unsigned int mEndTime;

 public:
  Meeting() :
      mStartTime(0),
      mEndTime(0)
  {
  }

  Meeting(unsigned int startTime, unsigned int endTime) :
      mStartTime(startTime),
      mEndTime(endTime)
  {
  }

  unsigned int getStartTime() const
  {
    return mStartTime;
  }

  void setStartTime(unsigned int startTime)
  {
    mStartTime = startTime;
  }

  unsigned int getEndTime() const
  {
    return mEndTime;
  }

  void setEndTime(unsigned int endTime)
  {
    mEndTime = endTime;
  }
};

//Brute force solution O(n^2) time O(n) space
vector<Meeting> mergeRangesBruteForce(const vector<Meeting>& meetings)
{
  vector<Meeting> mergedMeetings;
  set<size_t> processedMeetings;

  for (size_t i = 0; i < meetings.size(); ++i) {
    if (processedMeetings.find(i) != processedMeetings.end()) continue;
    Meeting first, second, current{meetings[i]};
    for (size_t j = i+1; j < meetings.size(); ++j) {
      if (processedMeetings.find(j) != processedMeetings.end()) continue;
      if (current.getStartTime() <= meetings[j].getStartTime()) {
        first = current;
        second = meetings[j];
      }
      else {
        first = meetings[j];
        second = current;
      }

      if (first.getEndTime() >= second.getStartTime()) {
        current.setStartTime(first.getStartTime());
        current.setEndTime(max(first.getEndTime(), second.getEndTime()));
        processedMeetings.insert(j);
      }

    }
    mergedMeetings.push_back(current);
  }
  return mergedMeetings;
}

vector<Meeting> mergeRanges(const vector<Meeting>& meetings)
{
  if (meetings.size() == 0) return {};

  vector<Meeting> sortedByStartTime(meetings.begin(), meetings.end());
  sort(sortedByStartTime.begin(), sortedByStartTime.end(), [](const Meeting& a, const Meeting&b){
                                                             return a.getStartTime() < b.getStartTime();
                                                           });

  vector<Meeting> mergedMeetings{sortedByStartTime.front()};

  for (const auto& meeting : sortedByStartTime) {
    //check if merge is possible
    if (mergedMeetings.back().getEndTime() >= meeting.getStartTime()) {
      mergedMeetings.back().setEndTime(max(meeting.getEndTime(),mergedMeetings.back().getEndTime()));

    }
    else {
      mergedMeetings.push_back(meeting);
    }
  }
 
  return mergedMeetings;
}

TEST(MergeMeetingsTest, MeetingsOverlap) {
  const auto meetings = vector<Meeting> {Meeting(1, 3), Meeting(2, 4)};
  const auto actual = mergeRanges(meetings);
  const auto expected = vector<Meeting> {Meeting(1, 4)};
  ASSERT_EQ(actual,expected);
}

  TEST(MergeMeetingsTest, MeetingsTouch) {
  const auto meetings = vector<Meeting> {Meeting(5, 6), Meeting(6, 8)};
  const auto actual = mergeRanges(meetings);
  const auto expected = vector<Meeting> {Meeting(5, 8)};
  ASSERT_EQ(actual,expected);
  }

  TEST(MergeMeetingsTest, MeetingContainsOtherMeeting) {
  const auto meetings = vector<Meeting> {Meeting(1, 8), Meeting(2, 5)};
  const auto actual = mergeRanges(meetings);
  const auto expected = vector<Meeting> {Meeting(1, 8)};
  ASSERT_EQ(actual,expected);
  }

  TEST(MergeMeetingsTest, MeetingsStaySeparate) {
  const auto meetings = vector<Meeting> {Meeting(1, 3), Meeting(4, 8)};
  const auto actual = mergeRanges(meetings);
  const auto expected = vector<Meeting> {Meeting(1, 3), Meeting(4, 8)};
  ASSERT_EQ(actual,expected);
  }

  TEST(MergeMeetingsTest, MultipleMergedMeetings) {
  const auto meetings = vector<Meeting> {Meeting(1, 4), Meeting(2, 5), Meeting(5, 8)};
  const auto actual = mergeRanges(meetings);
  const auto expected = vector<Meeting> {Meeting(1, 8)};
  ASSERT_EQ(actual,expected);
  }

  TEST(MergeMeetingsTest, MeetingsNotSorted) {
  const auto meetings = vector<Meeting> {Meeting(5, 8), Meeting(1, 4), Meeting(6, 8)};
  const auto actual = mergeRanges(meetings);
  const auto expected = vector<Meeting> {Meeting(1, 4), Meeting(5, 8)};
  ASSERT_EQ(actual,expected);
  }

  TEST(MergeMeetingsTest, OneLongMeetingContainsSmallerMeetings) {
  const auto meetings = vector<Meeting> {Meeting(1, 10), Meeting(2, 5), Meeting(6, 8),
  Meeting(9, 10), Meeting(10, 12)};
  const auto actual = mergeRanges(meetings);
  const auto expected = vector<Meeting> {Meeting(1, 12)};
  ASSERT_EQ(actual,expected);
  }

  TEST(MergeMeetingsTest, SampleInput) {
  const auto meetings = vector<Meeting> {Meeting(0, 1), Meeting(3, 5), Meeting(4, 8),
  Meeting(10, 12), Meeting(9, 10)};
  const auto actual = mergeRanges(meetings);
  const auto expected = vector<Meeting> {Meeting(0, 1), Meeting(3, 8), Meeting(9, 12)};
  ASSERT_EQ(actual,expected);
  }

int main (int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
