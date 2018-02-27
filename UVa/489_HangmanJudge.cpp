#include <iostream>
#include <set>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int round;
    scanf("%d", &round);

    while (round != -1) {
        printf("Round %d\n", round);
        char question[256], guesses[256];
        scanf("%s", question);
        scanf("%s", guesses);

        set<char> question_set, guesses_set;
        int i;
        for (i = 0; i < strlen(question); i++) {
            question_set.insert(question[i]);
        }

        int stroke = 0;
        set<char>::iterator it;
        bool flag_result_achieved = false;
        for (i = 0; i < strlen(guesses); i++) {
            if (guesses_set.find(guesses[i]) == guesses_set.end()) {
                if (question_set.size() > 0) {
                    if (question_set.find(guesses[i]) == question_set.end()) {
                        stroke++;
                    } else {
                        question_set.erase(question_set.find(guesses[i]));
                    }
                } else {
                    printf("You win.\n");
                    flag_result_achieved = true;
                    break;
                }
                if (stroke >= 7) {
                    printf("You lose.\n");
                    flag_result_achieved = true;
                    break;
                }
                guesses_set.insert(guesses[i]);
            }
            
        }

        if (!flag_result_achieved) {
            if (question_set.size() == 0) {
                printf("You win.\n");
            } else
                printf("You chickened out.\n");
        }

        scanf("%d", &round);
    }

    return 0;
}