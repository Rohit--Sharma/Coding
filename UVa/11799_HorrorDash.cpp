#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    int i = 1;
    while (t--) {
        int n;
        scanf("%d", &n);
        int max_speed = 0;
        while (n--) {
            int speed;
            scanf("%d", &speed);
            if (speed > max_speed) {
                max_speed = speed;
            }
        }
        printf("Case %d: %d\n", i++, max_speed);
    }

    return 0;
}