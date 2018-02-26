#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
    int n, a, b;
    scanf("%d", &n);
    while (n--) {
        scanf ("%d %d", &a, &b);
        (a > b) ? printf(">\n") : ((a < b) ? printf("<\n") : printf("=\n"));
    }
    return 0;
}