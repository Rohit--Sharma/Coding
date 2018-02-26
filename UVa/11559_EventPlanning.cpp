#include <cstdio>
using namespace std;

int main()
{
    int n, b, h, w;
    
    while (scanf("%d %d %d %d", &n, &b, &h, &w) != EOF)
    {
        long max = 500005;
        int p, a;
        //printf("%d %d %d %d\n", n, b, h, w);
        while (h--)
        {
            scanf("%d", &p);
            //printf("%d\n", p);
            int i = w;
            while (i--)
            {
                scanf("%d", &a);
                //printf("%d ", a);
                if (a >= n)
                {
                    long preTotal = p * n;
                    //printf("Pretotal: %ld\tMax: %ld\n", preTotal, max);
                    if (preTotal <= b && preTotal < max)
                    {
                        max = preTotal;
                    }
                }
            }
            //printf("\n");
        }
        (max == 500005) ? printf("stay home\n") : printf("%ld\n", max);
    }
    return 0;
}