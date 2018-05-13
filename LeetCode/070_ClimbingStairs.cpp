#include <cstdio>

using namespace std;

/// Can be solved by Fibonacci series
/// The below approach takes O(n) time and O(1) space to find fib(n).
///    but, fib(n) can also be computed in O(log n) time and O(1) space
///    using Binet's matrix mult method or fib formula method
int climbStairs(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    
    int n1 = 1, n2 = 2, ans = 0;
    for (int i = 2; i < n; i++) {
        ans = (n1 + n2);
        n1 = n2;
        n2 = ans;
    }

    return ans;
}

int main()
{
    printf("Ans: %d\n", climbStairs(5));
    return 0;
}