#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

// TODO: Analyze why this always works! :)
int min_stacks(char *containers) {
    stack<char> stacks[26];
    int stack_count = 0;

    stacks[stack_count++].push(containers[0]);

    for (int i = 1; i < strlen(containers); i++) {
        int j;
        for (j = 0; j < stack_count; j++) {
            if (containers[i] <= stacks[j].top()) {
                stacks[j].push(containers[i]);
                break;
            }
        }
        if (j == stack_count) {
            stacks[stack_count++].push(containers[i]);
        }
    }

    return stack_count;
}

int main()
{
    char input[1010];
    int case_num = 1;
    while (scanf("%s", input), strcmp(input, "end")) {
        int num_stacks = min_stacks(input);
        printf("Case %d: %d\n", case_num++, num_stacks);
    }
    return 0;
}