#include <cstdio>
#include <stack>
#include <iostream>

using namespace std;

class MyQueue{
    public:
        /** Initialize your data structure here. */
        MyQueue() {

        }

       /** Push element x to the back of queue. */
        void push(int x) {
            myStack1.push(x);
        }
        
        /** Removes the element from in front of queue and returns that element. */
        int pop() {
            int sz = myStack1.size();
            while (sz > 1) {
                myStack2.push(myStack1.top());
                myStack1.pop();
                sz--;
            }
            int top = myStack1.top();
            myStack1.pop();
            while (myStack2.size() > 0) {
                myStack1.push(myStack2.top());
                myStack2.pop();
            }
            return top;
        }
        
        /** Get the front element. */
        int peek() {
            int sz = myStack1.size();
            while (sz > 1) {
                myStack2.push(myStack1.top());
                myStack1.pop();
                sz--;
            }
            int top = myStack1.top();
            while (myStack2.size() > 0) {
                myStack1.push(myStack2.top());
                myStack2.pop();
            }
            return top;
        }
        
        /** Returns whether the queue is empty. */
        bool empty() {
            return myStack1.empty();
        }
    
    private:
        stack<int> myStack1;
        stack<int> myStack2;
};

int main()
{
    MyQueue obj = MyQueue();
    obj.push(2);
    obj.push(3);
    obj.push(5);
    int popped = obj.pop();
    int peeked = obj.peek();
    bool isEmpty = obj.empty();
    obj.pop();
    obj.pop();
    bool isEmptyNow = obj.empty();

    cout << popped << " " << peeked << " " << isEmpty << " " << isEmptyNow << endl;

    return 0;
}