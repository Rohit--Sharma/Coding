#include <cstdio>
#include <bitset>

using namespace std;

int main()
{
    int n, m, test_case = 0;
    while (scanf("%d %d", &n, &m), test_case++, (n || m))
    {

        int start, end, rep_int;
        bitset<1000005> schedule;
        bool is_conflict = false;

        while (n--)
        {
            scanf("%d %d", &start, &end);
            for (int i = start; (i < end); i++)
            {
                if (schedule.test(i))
                {
                    is_conflict = true;
                    break;
                }
                schedule.set(i);
            }
        }

        while (m--)
        {
            scanf("%d %d %d", &start, &end, &rep_int);
            int counter = 0, i = 0;
            while (!is_conflict && i < 1000000)
            {
                for (i = start + rep_int * counter; !is_conflict && (i < 1000000) && (i < end + rep_int * counter); i++)
                {
                    if (i < 1000000) {
                        if (schedule.test(i))
                        {
                            is_conflict = true;
                            break;
                        }
                        schedule.set(i);
                    }
                }
                counter++;
            }
        }

        if (is_conflict)
            printf("CONFLICT\n");
        else
            printf("NO CONFLICT\n");
    }
    return 0;
}