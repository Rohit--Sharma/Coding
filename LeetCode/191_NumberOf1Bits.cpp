#include <cstdio>
#include <cstdint>

using namespace std;

int hammingWeight(uint32_t n)
{
    int i = 32, result = 0;
    while (i--) {
        result += (n ^ 1);
        n >>= 1;
    }
}