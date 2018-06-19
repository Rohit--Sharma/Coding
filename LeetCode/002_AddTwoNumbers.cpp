#include <cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *nextSumNode(ListNode *l1, ListNode *l2, int carry)
{
    if (l1 == NULL && l2 == NULL)
        return new ListNode(carry);

    if (l1 == NULL) {
        int digitSum = l2->val + carry;
        ListNode *temp = new ListNode(digitSum % 10);
        temp->next = nextSumNode(NULL, l2->next, digitSum / 10);
        return temp;
    }
    if (l2 == NULL) {
        int digitSum = l1->val + carry;
        ListNode *temp = new ListNode(digitSum % 10);
        temp->next = nextSumNode(l1->next, NULL, digitSum / 10);
        return temp;
    }
    
    int digitSum = l1->val + l2->val + carry;
    ListNode *temp = new ListNode(digitSum % 10);
    temp->next = nextSumNode(l1->next, l2->next, digitSum / 10);
    return temp;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    
    int digitSum = l1->val + l2->val;

    ListNode *result = new ListNode(digitSum % 10);
    result->next = nextSumNode(l1->next, l2->next, digitSum / 10);
    return result;

    // int carry = 0;
    // while (l2 != NULL) {
    //     if (l1 != NULL) {
    //         int digitSum = l1->val + l2->val + carry;
    //         l1->val = digitSum % 10;
    //         carry = digitSum / 10;
    //         l1 = l1->next;
    //         l2 = l2->next;
    //     }
            
    // }
    // if (carry != 0)
    //     l1->next = new ListNode(carry);
    // return head;
}

int main()
{

    return 0;
}