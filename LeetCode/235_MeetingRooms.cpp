#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
		if (intervals.size() == 0)
			return 0;

        sort(intervals.begin(), intervals.end(), less_than());
		int num_meeting_rooms = 1;
		for (int i = 1; i < intervals.size(); i++)
			if (intervals[i].start < intervals[i - 1].end)
				num_meeting_rooms++;

		return num_meeting_rooms;
    }

private:
	struct less_than {
		inline bool operator() (const Interval& int1, const Interval& int2) {
			return int1.start < int2.start;
		}
	};
};

int main()
{
	vector<Interval> input = { Interval(5, 10), Interval(0, 30), Interval(15, 20) };
	cout << Solution().minMeetingRooms(input) << endl;

	input = { Interval(7, 10), Interval(2, 4) };
	cout << Solution().minMeetingRooms(input) << endl;

    return 0;
}