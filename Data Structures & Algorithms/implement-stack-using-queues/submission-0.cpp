class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
    }
    int pop() {
        int cnt = q.size();
        // dequeue cnt times
        for (int i = 0; i < cnt-1; ++i) {
            int x = q.front();
            q.pop();
            q.push(x);
        }
        // front of queue is now the top of stack
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        int cnt = q.size();
        // dequeue cnt times
        int x;
        for (int i = 0; i < cnt; ++i) {
            x = q.front();
            q.pop();
            q.push(x);
        }
        return x; 
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */