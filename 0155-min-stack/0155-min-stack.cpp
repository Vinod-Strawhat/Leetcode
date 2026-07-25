class MinStack {
public:
stack<int> s;
stack<int> m;
int mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        s.push(value);
        if(!m.empty()){
            if(value<=m.top()){
                m.push(value);
            }
        }
        else{
            m.push(value);
        }

    }
    
    void pop() {
        //s.pop();
        if(s.top()==m.top()){
            m.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */