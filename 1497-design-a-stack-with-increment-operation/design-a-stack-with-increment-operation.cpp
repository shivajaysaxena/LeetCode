class CustomStack {
private:
    vector<int> stack;
    int maxSize;

public:
    CustomStack(int maxSize) : maxSize(maxSize) {}

    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }

    int pop() {
        if (stack.empty()) {
            return -1;
        }
        int top = stack.back();
        stack.pop_back();
        return top;
    }

    void increment(int k, int val) {
        int limit = min(k, (int)stack.size());
        for (int i = 0; i < limit; i++) {
            stack[i] += val;
        }
    }
};