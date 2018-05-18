#include <cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode *node)
{
    // Assuming the node to be deleted is not the last one
    node->val = node->next->val;
    node->next = node->next->next;
}