#include <set>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>

using std::vector;
using std::max;
using std::min;
using std::set;

class Meeting
{
 private:
  unsigned int startTime_;
  unsigned int endTime_;

 public:
  Meeting() :
      startTime_(0),
      endTime_(0)
  {
  }

  Meeting(unsigned int startTime, unsigned int endTime) :
      startTime_(startTime),
      endTime_(endTime)
  {
  }

  unsigned int getStartTime() const
  {
    return startTime_;
  }

  void setStartTime(unsigned int startTime)
  {
    startTime_ = startTime;
  }

  unsigned int getEndTime() const
  {
    return endTime_;
  }

  void setEndTime(unsigned int endTime)
  {
    endTime_ = endTime;
  }

  bool operator==(const Meeting& other) const
  {
    return
        startTime_ == other.startTime_
        && endTime_ == other.endTime_;
  }

  bool operator!=(const Meeting& other) const
  {
    return
        startTime_ != other.startTime_
        || endTime_ != other.endTime_;
  }
};

vector<Meeting> mergeRanges(const vector<Meeting>& meetings)
{
  vector<Meeting> mergedMeetings;
  set<size_t> processedMeetings;

  for (size_t i = 0; i < meetings.size(); ++i) {
    if (processedMeetings.find(i) != processedMeetings.end()) continue;
    Meeting first, second, current{meetings[i]};
    std::cout << current.getStartTime() << " iii  " << current.getEndTime() << std::endl;
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

      if (first.getEndTime() <= second.getStartTime()) {
        current.setStartTime(first.getStartTime());
        current.setEndTime(max(first.getEndTime(), second.getEndTime()));
        processedMeetings.insert(j);
        std::cout << current.getStartTime() << " mmm  " << current.getEndTime() << std::endl;
      }

    }
    mergedMeetings.push_back(current);
    std::cout << current.getStartTime() << " " << current.getEndTime() << std::endl;
  }
    return mergedMeetings;
}
#if 0
vector<Meeting> mergeRanges(const vector<Meeting>& meetings)
{
  if (meetings.size() == 0) return {};

  // merge meeting ranges
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
#endif



// tests1,3 2,4
TEST(MergeMeetingsTest, MeetingsOverlap) {
  const auto meetings = vector<Meeting> {Meeting(3, 6), Meeting(1, 2)};
  const auto actual = mergeRanges(meetings);
  const auto expected = vector<Meeting> {Meeting(1, 4)};
  ASSERT_EQ(actual,expected);
}
/*
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
*/
int main (int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
