#include <cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
    ListNode *first = head, *pointer = head;

    if (pointer == NULL)
        return pointer;
    
    int temp = pointer->val;
    while (pointer != NULL) {
        while (pointer->next != NULL && pointer->next->val == temp) {
            pointer->next = pointer->next->next;
        }
        pointer = pointer->next;
        if (pointer != NULL)
            temp = pointer->val;
    }

    return first;
}

int main()
{

    return 0;
}