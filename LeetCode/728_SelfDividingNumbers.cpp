#include <iostream>
#include <vector>

using namespace std;

bool selfDividing(int x)
{
    int num = x;

    while (num) {
        if (num % 10 == 0 || (x % (num % 10)) != 0)
            return false;
        num /= 10;
    }

    return true;
}

vector<int> selfDividingNumbers(int left, int right)
{
    vector<int> result;

    for (int i = left; i <= right; i++)
        if (selfDividing(i))
            result.push_back(i);

    return result;
}

int main()
{
    vector<int> out = selfDividingNumbers(1, 22);

    for (int n : out)
        cout << n << " ";
    cout << endl;

    return 0;
}