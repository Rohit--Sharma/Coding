#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cse = 1;
    int arr[] = {0, 1, 2};

    scanf("%d", &n);
    while (n--) {
        scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

        sort(arr, arr + 3);
        printf("Case %d: %d\n", cse++, arr[1]);
    }
}