#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int num_crosses(int ferry_length, vector<int> left, vector<int> right)
{
    queue<int> queue_ferry;
    int result = 0;
    int loaded_cargo = 0;
    int i = 0, j = 0;
    //printf("Param: %d, %d, %d\n", ferry_length, (int)left.size(), (int)right.size());
    while (1) {
        //printf("%d %d\n", i, j);
        while (queue_ferry.size()) {
            loaded_cargo -= queue_ferry.front();
            queue_ferry.pop();
        }
        if (i < left.size()) {
            for (; i < left.size(); i++) {
                if (loaded_cargo + left[i] <= ferry_length) {
                    loaded_cargo += left[i];
                    queue_ferry.push(left[i]);
                } else {
                    break;
                }
            }
            result++;
            //printf("left i: %d, crosses: %d\n", i, result);
        }
        else if ((i == left.size()) && (j < right.size())) {
            result++;
            //printf("Empty left -> right cross: %d\n", result);
        }
        while (queue_ferry.size()) {
            loaded_cargo -= queue_ferry.front();
            queue_ferry.pop();
        }
        if (j < right.size()) {
            for (; j < right.size(); j++) {
                if (loaded_cargo + right[j] <= ferry_length) {
                    loaded_cargo += right[j];
                    queue_ferry.push(right[j]);
                } else {
                    break;
                }
            }
            result++;
            //printf("right j: %d, crosses: %d\n", j, result);
        }
        else if ((i < left.size()) && (j == right.size())) {
            result++;
            //printf("Empty right -> left cross: %d\n", result);
        }

        if (i == left.size() && j == right.size())
            return result;
    }
    return result;
}

int main()
{
    int c;
    scanf("%d", &c);

    while (c--) {
        int l_ferry, m;
        scanf("%d %d", &l_ferry, &m);
        l_ferry *= 100;
        vector<int> left_cargos, right_cargos;

        while (m--) {
            int l_car;
            char side[8];
            scanf("%d %s", &l_car, side);
            if (!strcmp(side, "left")) {
                left_cargos.push_back(l_car);
            } else {
                right_cargos.push_back(l_car);
            }
        }

        printf("%d\n", num_crosses(l_ferry, left_cargos, right_cargos));
    }

    return 0;
}