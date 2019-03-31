#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

class Solution_BruteForce {
public:
    int countPrimes(int n) {
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime(i)) {
                // cout << i << endl;
                count++;
            }
        }
        return count;
    }

private:
    bool isPrime(int x) {
        for(int i = 2; i <= sqrt(x); i++) {
            if(x % i == 0) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        int num_primes = 0;
        vector<bool> primes(n, true);
        for (int i = 3; i < n; i++) {
            if (primes[i] == true) {
                num_primes++;
                for (int j = 2*i; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }
        return num_primes;
    }
};

int main() {
    int input;
    cin >> input;
    cout << Solution().countPrimes(input) << endl;
    return 0;
}
