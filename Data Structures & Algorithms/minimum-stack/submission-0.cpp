class MinStack {
    stack<int> s;
    multiset<int> m;
public:
    MinStack() {
        s = {};
        m.clear();
    }
    
    void push(int val) {
        s.push(val);
        m.insert(val);
    }
    
    void pop() {
        int top = s.top();
        s.pop();
        m.erase(m.find(top));
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return *m.begin();
    }
};
