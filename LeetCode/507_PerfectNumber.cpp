#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

// Returns list of divisors for n
vector<int> divisors(int n)
{
    vector<int> div;
    // Note that this loop runs till square root
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal, return only one
            if (n / i == i)
                div.push_back(i);
 
            else {// Otherwise return both
                div.push_back(i);
                div.push_back(n / i);
            }
        }
    }
    return div;
}

/// Time complexity: O(sqrt(n)) Space complexity: O(n) // can be done in O(1) space if implemented in same method.
/// A better algorithm uses Euclid-Euler Theorem to do it in O(lg n) space and time complexity
bool checkPerfectNumber(int num)
{
    int sum = 0;
    for (int n : divisors(num))
        if (n != num)
            sum += n;
    return (sum == num);
}

int main()
{
    int input;
    scanf("%d", &input);
    printf("%d\n", checkPerfectNumber(input));
    return 0;
}