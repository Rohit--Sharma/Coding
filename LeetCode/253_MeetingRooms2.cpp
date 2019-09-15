#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
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

/**
 * Idea from the following link:
 * http://blog.gainlo.co/index.php/2016/07/12/meeting-room-scheduling-problem/
 */
class Solution {
public:
	int minMeetingRooms(vector<Interval>& intervals) {
		if (intervals.size() == 0)
			return 0;

		vector<Time> times;
		for (auto interval : intervals) {
			times.push_back(Time(interval.start, true));
			times.push_back(Time(interval.end, false));
		}

		sort(times.begin(), times.end(), less_than());
		int num_curr_meet_rooms = 0, min_meet_rooms = 0;
		for (int i = 0; i < times.size(); i++)
			if (times[i].is_start) {
				num_curr_meet_rooms++;
				min_meet_rooms = max(min_meet_rooms, num_curr_meet_rooms);
			} else {
				num_curr_meet_rooms--;
			}

		return min_meet_rooms;
	}

private:
	struct Time {
		int time;
		bool is_start;
		Time(int t, bool st) : time(t), is_start(st) {}
	};

	struct less_than {
		inline bool operator() (const Time& t1, const Time& t2) {
			if (t1.time == t2.time)
				return t1.is_start == false;
			return t1.time < t2.time;
		}
	};
};

// Another approach
class Solution_II {
public:
	int minMeetingRooms(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), [](const Interval a, const Interval b){
			return a.start < b.start;
		});
		
		for (Interval interval: intervals) {
			AddMeeting(interval);
		}
		return rooms.size();
	}

private:
	vector<vector<Interval>> rooms;

	void AddMeeting(Interval interval) {
		for (int i = 0; i < rooms.size(); i++) {
			if (isValid(interval, rooms[i])) return;
		}

		rooms.push_back({interval});
	}
	
	bool isValid(Interval interval, vector<Interval> &room) {
		Interval roomInterval = room.back();
		if (interval.start < roomInterval.end) return false;
		room.push_back(interval);
		return true;
	}
};

int main() {
	vector<Interval> intervals;

	intervals = {Interval(2, 11), Interval(6, 16), Interval(11, 16)};
	cout << Solution().minMeetingRooms(intervals) << endl;

	intervals = {Interval(1, 4), Interval(5, 6), Interval(8, 9), Interval(2, 6)};
	cout << Solution().minMeetingRooms(intervals) << endl;

	intervals = {Interval(0, 30), Interval(5, 10), Interval(15, 20)};
	cout << Solution().minMeetingRooms(intervals) << endl;

	intervals = {Interval(7, 10), Interval(2, 4)};
	cout << Solution().minMeetingRooms(intervals) << endl;

	return 0;
}