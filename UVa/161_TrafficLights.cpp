#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int first_num;
    while (scanf("%d", &first_num), first_num) {
        vector<int> times, green_red_range_times;

        times.push_back(first_num);
        green_red_range_times.push_back(first_num * 2);

        int num;
        int min_time = first_num;
        while (scanf("%d", &num), num) {
            times.push_back(num);
            green_red_range_times.push_back(num * 2);
            if (num < min_time)
                min_time = num;
        }

        int curr_time = min_time * 2;
        bool flag_all_green = false;
        while (curr_time <= 18000 && !flag_all_green) {
            int i;
            for (i = 0; i < times.size(); i++) {
                if (curr_time % green_red_range_times[i] >= times[i] - 5) {
                    curr_time++;
                    break;
                }
            }
            if (i == times.size())
                flag_all_green = true;
            
        }
        if (flag_all_green) {
            int hr = curr_time / 3600;
            printf("0%d:%02d:%02d\n", curr_time / 3600, (curr_time - hr * 3600) / 60, curr_time % 60);
        } else {
            printf("Signals fail to synchronise in 5 hours\n");
        }

    }

    return 0;
}