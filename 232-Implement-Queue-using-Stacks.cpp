class MyQueue {
public:
    MyQueue() {
    }
    
    void push(int x) {
        one.push(x);
    }
    
    int pop() {
        push_one_two();
        int temp = two.top();
        two.pop();
        push_two_one();
        return temp;
    }
    
    int peek() {
        push_one_two();
        int temp = two.top();
        push_two_one();
        return temp;
    }
    
    bool empty() {
        return one.empty() && two.empty();
    }

private:
    stack<int> one;
    stack<int> two;

    void push_two_one() {
        while(!two.empty()) {
            one.push(two.top());
            two.pop();
        }
    }

    void push_one_two() {
        while(!one.empty()) {
            two.push(one.top());
            one.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */