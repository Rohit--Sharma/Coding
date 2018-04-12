#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    string temp;
    getline(cin, temp);
    getline(cin, temp);
    while (t--) {
        map<string, int> myMap;

        string tree;
        int total_trees_count = 0;
        while (getline(cin, tree), tree.size()) {
            total_trees_count++;
            if (!myMap.count(tree)) {
                myMap[tree] = 1;
            } else {
                myMap[tree]++;
            }
        }

        for (map<string, int>::iterator it = myMap.begin(); it != myMap.end(); it++) {
            cout.setf(ios::fixed);
            cout << it->first << ' ' << setprecision(4) << (float)it->second / total_trees_count * 100.0 << '\n';
        }
        cout << '\n';
    }
    return 0;
}