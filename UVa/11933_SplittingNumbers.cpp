#include <cstdio>
#include <bitset>
#include <cmath>

using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n), n) {
        int a = 0, b = 0;
        int i = 0, j = 0;
        do {
            if (n % 2) {
                if (j % 2) {
                    b += (1 << i);
                } else {
                    a += (1 << i);
                }
                j++;
            }
            i++;
            n >>= 1;
        } while (n);
        printf ("%d %d\n", a, b);
    }
    return 0;
}