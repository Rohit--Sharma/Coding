#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;

/// Implementing stack with only one queue.
///    Time complexity: Push: O(n), Pop: O(1)
class MyStack
{
    public:
        /** Initialize your data structure here. */
        MyStack() {
            
        }
        
        /** Push element x onto stack. */
        void push(int x) {
            myQueue.push(x);
            int sz = myQueue.size();
            while (sz > 1) {
                int oldest = myQueue.front();
                myQueue.push(oldest);
                myQueue.pop();
                sz--;
            }
        }
        
        /** Removes the element on top of the stack and returns that element. */
        int pop() {
            int oldest = myQueue.front();
            myQueue.pop();
            return oldest;
        }
        
        /** Get the top element. */
        int top() {
            return myQueue.front();
        }
        
        /** Returns whether the stack is empty. */
        bool empty() {
            return myQueue.empty();
        }
    
    private:
        queue<int> myQueue;
};

int main()
{
    // Your MyStack object will be instantiated and called as such:
    MyStack obj = MyStack();
    obj.push(1);
    obj.push(2);
    int param_2 = obj.pop();
    int param_3 = obj.pop();
    bool param_4 = obj.empty();

    printf("%d %d\n", param_2, param_3);
    cout << param_4 << endl;

    return 0;
}