#include <cstdio>
#include <cmath>

using namespace std;

int num_digits(int x)
{
    int result = 0;
    while (x)
    {
        x /= 10;
        result++;
    }
    return result;
}

int first_digit(int x)
{
    int n_digits = num_digits(x);
    for (int i = 0; i < n_digits - 1; i++)
    {
        x /= 10;
    }
    return x;
}

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    while (x)
    {
        printf("\nx: %d, n_dgts: %d, First: %d, Last: %d", x, num_digits(x), first_digit(x), x % 10);
        if ((x % 10) != first_digit(x))
            return false;
        x = (x - pow(10, num_digits(x) - 1) * first_digit(x)) / 10;
    }
    return true;
}

int reverse_number(int x)
{
    int result = 0;
    while (x)
    {
        //printf ("x: %d\tlast: %d\n", x, x % 10);
        result += (x % 10);
        x /= 10;
        if (x == 0) {
            return result;
        }
        result *= 10;
    }
    return result / 10;
}

bool isPalindrome_reverse(int x)
{
    if (x < 0)
        return false;
    printf("\nReverse: %d", reverse_number(x));
    if (x == reverse_number(x))
        return true;
    else
        return false;
}

int main()
{
    int n;

    n = 1000000001;
    printf("%d: ", n);
    if (isPalindrome_reverse(n))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}