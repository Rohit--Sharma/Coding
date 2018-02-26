#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int dur_mnths, no_dep_rec, prev_mnth_counter = -1, curr_mnth_counter;
    float downpayment, amount;

    float amount_owed, car_worth, installment;

    scanf("%d %f %f %d", &dur_mnths, &downpayment, &amount, &no_dep_rec);
    while (dur_mnths >= 0) {
        vector<float> dep_perc;
        car_worth = amount + downpayment;
        installment = amount / dur_mnths;
        amount_owed = amount;
        amount_owed += installment;

        int i = dur_mnths;
        while (i--) {
            dep_perc.push_back(0);
        }
        i = no_dep_rec;
        while (i--) {
            int month;
            float depreciation;
            scanf("%d %f", &month, &depreciation);
            dep_perc[month] = depreciation;
        }
        float past_dep = dep_perc[0];
        for (i = 1; i < dur_mnths; i++) {
            if (dep_perc[i] == 0)
                dep_perc[i] = past_dep;
            else
                past_dep = dep_perc[i];
        }

        //printf("Dep_perc:\n");
        // for (i = 0; i < dur_mnths; i++) {
        //     printf("%d: %f\n", i, dep_perc[i]);
        // }

        for (i = 0; i <= dur_mnths; i++) {
            
            car_worth = car_worth * (1 - dep_perc[i]);
            amount_owed = amount_owed - installment;
            //printf("%d: %f\t%f\n", i, car_worth, amount_owed);
            if (car_worth > amount_owed) {
                if (i == 1) {
                    printf("1 month\n");
                    break;
                }
                printf("%d months\n", i);
                break;
            }
            
        }
        scanf("%d %f %f %d", &dur_mnths, &downpayment, &amount, &no_dep_rec);
    }

    return 0;
}