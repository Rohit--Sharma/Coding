#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if (head->next == NULL)
        return NULL;
    ListNode *nodeToDelete = head, *lastNode = head;
    while (n--) {
        lastNode = lastNode->next;
    }

    ListNode *prevNode = NULL;
    while (lastNode != NULL) {
        prevNode = nodeToDelete;
        nodeToDelete = nodeToDelete->next;
        lastNode = lastNode->next;
    }

    if (nodeToDelete->next != NULL) {
        nodeToDelete->val = nodeToDelete->next->val;
        nodeToDelete->next = nodeToDelete->next->next;
    }
    else
        prevNode->next = NULL;

    return head;
}

int main()
{

    return 0;
}