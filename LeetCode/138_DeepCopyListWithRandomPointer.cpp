#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        
        RandomListNode *outHead = new RandomListNode(head->label);
        RandomListNode *result = outHead;
        map<RandomListNode *, RandomListNode *> oldAddressToNewAddressMap;
        if (head->random != NULL) {
            outHead->random = new RandomListNode(head->random->label);
            oldAddressToNewAddressMap[head->random] = outHead->random;
        }
        else {
            outHead->random = NULL;
        }
        head = head->next;
        while (head != NULL) {
            if (oldAddressToNewAddressMap.find(head) != oldAddressToNewAddressMap.end()) {
                outHead->next = oldAddressToNewAddressMap[head];
            }
            else {
                outHead->next = new RandomListNode(head->label);
                oldAddressToNewAddressMap[head] = outHead->next;
            }
            outHead = outHead->next;

            if (head->random != NULL) {
                if (oldAddressToNewAddressMap.find(head->random) != oldAddressToNewAddressMap.end()) {
                    outHead->random = oldAddressToNewAddressMap[head->random];
                }
                else {
                    outHead->random = new RandomListNode(head->random->label);
                    oldAddressToNewAddressMap[head->random] = outHead->random;
                }
            }

            head = head->next;
        }

        return result;
    }

    void displayRandomList(RandomListNode *head) {
        while (head != NULL) {
            cout << head->label << " ";
            if (head->random != NULL) {
                cout << head->random->label << endl;
            }
            else {
                cout << "NULL" << endl;
            }
            head = head->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    RandomListNode *inp1 = new RandomListNode(1),
        *inp2 = new RandomListNode(2),
        *inp3 = new RandomListNode(3),
        *inp4 = new RandomListNode(4),
        *inp5 = new RandomListNode(5),
        *inp6 = new RandomListNode(6);
    
    inp1->next = inp2;
    inp1->random = inp3;
    
    inp2->next = inp3;
    inp2->random = inp6;
    
    inp3->next = inp4;
    
    inp4->next = inp5;
    
    inp5->next = inp6;
    inp5->random = inp6;
    
    inp6->random = inp3;

    RandomListNode *out = Solution().copyRandomList(inp1);

    Solution().displayRandomList(out);

    return 0;
}