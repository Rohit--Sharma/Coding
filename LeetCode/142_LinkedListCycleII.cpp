#include <cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/// Return value NULL corresponds to no cycle and a node corresponds to cycle being found
ListNode *hasCycle(ListNode *head) 
{
    if (head == NULL)
        return NULL;
    ListNode *ptr1, *ptr2;
    ptr1 = ptr2 = head;
    
    while (ptr2->next != NULL && ptr2->next->next != NULL) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
        if (ptr1 == ptr2)
            return ptr1;
    }
    return NULL;
}

/// Refer to Cracking the Coding Interview for algo
ListNode *detectCycle(ListNode *head)
{
    ListNode *ptr1 = head, *ptr2 = hasCycle(head);
    if (ptr2 == NULL)
        return NULL;
    
    while (ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr2;
}