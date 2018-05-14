#include <cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) 
{
    if (head == NULL)
        return false;
    ListNode *ptr1, *ptr2;
    ptr1 = ptr2 = head;
    
    while (ptr2->next != NULL && ptr2->next->next != NULL) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
        if (ptr1 == ptr2)
            return true;
    }
    return false;
}