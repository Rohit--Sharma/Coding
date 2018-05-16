#include <cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/// Time comlexity: O(n), Space complexity: O(1)
ListNode *reverseListIter(ListNode *head)
{
    ListNode *prev = NULL, *curr = head;
    ListNode *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

/// Time comlexity: O(n), Space complexity: O(n)
ListNode* reverseListRec(ListNode* head) 
{
    if (head == NULL || head->next == NULL)
        return head;
    
    ListNode *temp = reverseListRec(head->next);
    
    // Critical step
    head->next->next = head;
    head->next = NULL;
    return temp;
}