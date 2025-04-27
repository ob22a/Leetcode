class MinStack {
public:
    int minimum=INT_MAX;
    vector<int> myStack;
    MinStack() {}
    
    void push(int val) {
        minimum=min(val,minimum);
        myStack.push_back(val);
    }
    
    void pop() {
        int last=myStack.back();
        myStack.pop_back();
        if(minimum==last){
            if(!myStack.empty()){
                minimum=myStack[0];
                for(int num:myStack){
                    minimum=min(minimum,num);
                }
            }
            else minimum=INT_MAX;
        }
    }
    
    int top() {
        return myStack.back();
    }
    
    int getMin() {
        return minimum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */