#include <cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode* result = NULL;
    ListNode* pointer = NULL;

    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    
    if (l1->val <= l2->val) {
        result = pointer = l1;
        l1 = l1->next;
    }
    else {
        result = pointer = l2;
        l2 = l2->next;
    }

    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            pointer->next = l1;
            l1 = l1->next;
        }
        else {
            pointer->next = l2;
            l2 = l2->next;
        }
        pointer = pointer->next;
    }

    if (l1 != NULL)
        pointer->next = l1;
    else if (l2 != NULL)
        pointer->next = l2;

    return result;
}

int main()
{

    return 0;
}