class MinStack {
public:
    stack<int> s, mini;
    void push(int val) {
        s.push(val);
        if (mini.size() == 0 || val <= mini.top()) {
            mini.push(val);
        }
    }

    void pop() {
        if (mini.top() == s.top())
            mini.pop();
        s.pop();
    }

    int top() { return s.top(); }

    int getMin() { return mini.top(); }
};