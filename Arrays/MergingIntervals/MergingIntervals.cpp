include <iostream>
#include <vector>
#include <gtest/gtest.h>

using std::vector;

class Meeting
{
private:
    // number of 30 min blocks past 9:00 am
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




// tests
  TEST(MergeMeetingsTest, MeetingsOverlap) {
        const auto meetings = vector<Meeting> {Meeting(1, 3), Meeting(2, 4)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(1, 4)};
        EXPECT(actual == expected);
    }

    TEST(MergeMeetingsTest, "Meetings Touch") {
        const auto meetings = vector<Meeting> {Meeting(5, 6), Meeting(6, 8)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(5, 8)};
        EXPECT(actual == expected);
    }

    TEST(MergeMeetingsTest, "Meeting Contains Other Meeting") {
        const auto meetings = vector<Meeting> {Meeting(1, 8), Meeting(2, 5)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(1, 8)};
        EXPECT(actual == expected);
    }

    TEST(MergeMeetingsTest, "Meetings Stay Separate") {
        const auto meetings = vector<Meeting> {Meeting(1, 3), Meeting(4, 8)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(1, 3), Meeting(4, 8)};
        EXPECT(actual == expected);
    },

    TEST(MergeMeetingsTest, "Multiple Merged Meetings") {
        const auto meetings = vector<Meeting> {Meeting(1, 4), Meeting(2, 5), Meeting(5, 8)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(1, 8)};
        EXPECT(actual == expected);
    },

    TEST(MergeMeetingsTest, "Meetings Not Sorted") {
        const auto meetings = vector<Meeting> {Meeting(5, 8), Meeting(1, 4), Meeting(6, 8)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(1, 4), Meeting(5, 8)};
        EXPECT(actual == expected);
    },

    TEST(MergeMeetingsTest, "One Long Meeting Contains Smaller Meetings") {
        const auto meetings = vector<Meeting> {Meeting(1, 10), Meeting(2, 5), Meeting(6, 8),
            Meeting(9, 10), Meeting(10, 12)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(1, 12)};
        EXPECT(actual == expected);
    },

    TEST(MergeMeetingsTest, "Sample Input") {
        const auto meetings = vector<Meeting> {Meeting(0, 1), Meeting(3, 5), Meeting(4, 8),
            Meeting(10, 12), Meeting(9, 10)};
        const auto actual = mergeRanges(meetings);
        const auto expected = vector<Meeting> {Meeting(0, 1), Meeting(3, 8), Meeting(9, 12)};
        EXPECT(actual == expected);
    },

};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
