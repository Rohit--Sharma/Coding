// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (guess(mid + 1) == 0)
                return mid + 1;
            if (guess(mid + 1) == -1)
                hi = mid - 1;
            if (guess(mid + 1) == 1)
                lo = mid + 1;
        }
        return -1;
    }
};