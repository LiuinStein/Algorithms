static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class MyStack {

    std::queue<int> q[2];

    int top(bool pop_last)
    {
        int from = q[0].empty() ? 1 : 0;
        int to = 1 - from;
        int size = q[from].size();
        for (int i = 0; i < size - 1; ++i)
        {
            q[to].push(q[from].front());
            q[from].pop();
        }
        int ret = q[from].front();
        if (!pop_last)
        {
            q[to].push(ret);
        }
        q[from].pop();
        return ret;
    }
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x)
    {
        (q[0].empty() ? q[1] : q[0]).push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        return top(true);
    }

    /** Get the top element. */
    int top() {
        return top(false);
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q[0].empty() && q[1].empty();
    }
};