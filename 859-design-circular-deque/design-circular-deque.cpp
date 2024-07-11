class MyCircularDeque {
public:
    deque<int> dq;
    int count = 0, full = 0;
    MyCircularDeque(int k) { full = k; }

    bool insertFront(int value) {
        if (count < full) {
            dq.push_front(value);
            count++;
            return true;
        } else {
            return false;
        }
    }

    bool insertLast(int value) {
        if (count < full) {
            dq.push_back(value);
            count++;
            return true;
        } else {
            return false;
        }
    }

    bool deleteFront() {
        if (count > 0) {
            dq.pop_front();
            count--;
            return true;
        } else {
            return false;
        }
    }

    bool deleteLast() {
        if (count > 0) {
            dq.pop_back();
            count--;
            return true;
        } else {
            return false;
        }
    }

    int getFront() {
        if (dq.empty()) {
            return -1;
        } else {
            return dq.front();
        }
    }

    int getRear() {
        if (dq.empty()) {
            return -1;
        } else {
            return dq.back();
        }
    }

    bool isEmpty() {
        if (dq.empty()) {
            return true;
        } else {
            return false;
        }
    }

    bool isFull() {
        if (count == full) {
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */