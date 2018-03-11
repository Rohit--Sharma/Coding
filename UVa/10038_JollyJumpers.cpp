#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<bool> flags (3010, false);
        bool is_jolly = true, is_first = true;
        int i, prev, curr;

        for(i = 0; i < n; i++) {
            scanf("%d", &curr);
            if (is_first) {
                is_first = false;
                prev = curr;
                continue;
            }

            //(curr > prev) ? (flags[curr - prev] = true) : (flags[prev - curr] = true);
            int index = (curr > prev) ? (curr - prev) : (prev - curr);
            //printf("Index: %d\n", index);
            if (index < 3009) {
                flags[index] = true;
            }
            prev = curr;
        }

        for (i = 1; i < n; i++) {
            if (flags[i] != true) {
                is_jolly = false;
                break;
            }
        }

        if (is_jolly) {
            printf("Jolly\n");
        } else {
            printf("Not jolly\n");
        }
    }
    return 0;
}