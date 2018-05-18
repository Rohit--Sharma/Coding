#include <cstdio>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
    public:
        int firstBadVersion(int n) {
            int lo = 0, hi = n - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                if (isBadVersion(mid + 1) == true && (mid == 0 || isBadVersion(mid) == false))
                    return mid + 1;
                
                if (isBadVersion(mid + 1) == true)
                    hi = mid - 1;
                
                if (isBadVersion(mid + 1) == false)
                    lo = mid + 1;
            }
            return -1;
        }
};

bool isBadVersion(int version)
{
    return (version >= 14) ? true : false;
}

int main()
{
    printf("%d\n", Solution().firstBadVersion(15));
    return 0;
}