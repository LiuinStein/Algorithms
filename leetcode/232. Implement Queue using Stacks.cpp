static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class MyQueue {
    std::stack<int> stk1, stk2;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        while (!stk1.empty())
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
        stk2.push(x);
        while (!stk2.empty())
        {
            stk1.push(stk2.top());
            stk2.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int t = stk1.top();
        stk1.pop();
        return t;
    }

    /** Get the front element. */
    int peek() {
        return stk1.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty();
    }
};