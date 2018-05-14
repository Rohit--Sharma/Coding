#include <cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *ptr1 = headA, *ptr2 = headB;

    bool flag1 = false, flag2 = false;
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)
            return ptr1;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

        if (ptr1 == NULL && !flag1) { 
            ptr1 = headB;
            flag1 = true;
        }
        if (ptr2 == NULL && !flag2) {
            ptr2 = headA;
            flag2 = true;
        }
    }
    return NULL;
}

int main()
{
    ListNode node1 = ListNode(1);
    ListNode node2 = ListNode(8);

    ListNode *intersection = getIntersectionNode(&node1, &node2);
    if (intersection != NULL)
        printf("Intersection: %d\n", intersection->val);
    else
        printf("No intersection found\n");

    ListNode node3 = ListNode(1);
    ListNode node5 = ListNode(2);
    ListNode node6 = ListNode(3);
    ListNode node7 = ListNode(4);
    ListNode node8 = ListNode(5);

    node7.next = &node8;
    node6.next = &node7;
    node5.next = &node6;
    node3.next = &node5;

    ListNode node4 = ListNode(8);
    node4.next = &node6;

    intersection = getIntersectionNode(&node3, &node4);
    if (intersection != NULL)
        printf("Intersection: %d\n", intersection->val);
    else
        printf("No intersection found\n");

    return 0;
}