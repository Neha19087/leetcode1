class MinStack {
public:
    stack<int>st;
    stack<int>getminst;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(getminst.empty()) getminst.push(value);
        else if(value<=getminst.top()){ 
            getminst.push(value);
        }
    }
    
    void pop() {
        if(getminst.top()==st.top()){
            getminst.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return getminst.top();
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