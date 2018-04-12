#include <cstdio>
#include <map>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        map<int, int> myMap;

        int n;
        scanf("%d", &n);
        
        while (n--) {
            int snow_flake;
            scanf("%d", &snow_flake);
            myMap[snow_flake] = 1;
        }

        printf("%d\n", (int)myMap.size());
    }
    return 0;
}