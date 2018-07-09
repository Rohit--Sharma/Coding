#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool comparator(Interval a, Interval b) {
    return (a.start < b.start);
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() <= 1)
            return intervals;
        
        sort(intervals.begin(), intervals.end(), comparator);

        vector<Interval> result;
        result.push_back(intervals[0]);

        int j = 0;  // result pos
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start <= result[j].end) {
                result[j].end = max(result[j].end, intervals[i].end);
            }
            else {
                result.push_back(intervals[i]);
                j++;
            }
        }

        return result;
    }
};

int main()
{
    vector<Interval> input {
        Interval(1, 5),
        Interval(2, 4),
        Interval(8, 11),
        Interval(6, 13),
        Interval(9, 12),
        Interval(11, 18)
    };
    // input.push_back(Interval(1, 5));
    // input.push_back(Interval(2, 4));
    // input.push_back(Interval(8, 11));
    // input.push_back(Interval(6, 13));
    // input.push_back(Interval(9, 12));
    // input.push_back(Interval(11, 18));

    auto res = Solution().merge(input);
    for (auto interval : res) {
        cout << interval.start << " " << interval.end << ", ";
    }
    cout << endl;

    input = vector<Interval> {
        Interval(1, 3),
        Interval(2, 6),
        Interval(8, 10),
        Interval(15, 18)
    };
    res = Solution().merge(input);
    for (auto interval : res) {
        cout << interval.start << " " << interval.end << ", ";
    }
    cout << endl;

    input = vector<Interval> {
        Interval(1, 4),
        Interval(4, 5)
    };
    res = Solution().merge(input);
    for (auto interval : res) {
        cout << interval.start << " " << interval.end << ", ";
    }
    cout << endl;   

    return 0;
}