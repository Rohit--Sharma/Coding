#include <cstdio>
using namespace std;

int main()
{
    int h, u, d, f;
    scanf("%d %d %d %d", &h, &u, &d, &f);
    while (h != 0) {
        int day = 1;

        float h_curr = 0;
        float d_curr = (float)u;
        float fatigue = d_curr * f / 100.0;

        while (1) {
            h_curr += d_curr;
            //printf("Day: %d\nd_curr: %f\n", day, d_curr);
            //printf("Ht_day: %f\n", h_curr);
            if (h_curr > h) {
                printf("success on day %d\n", day);
                break;
            }

            h_curr -= d;
            //printf("Ht_night: %f\n\n", h_curr);
            if (h_curr < 0) {
                printf("failure on day %d\n", day);
                break;
            }
            day++;
            d_curr -= fatigue;
            if (d_curr < 0) {
                d_curr = 0;
            }
        }

        scanf("%d %d %d %d", &h, &u, &d, &f);
    }
}