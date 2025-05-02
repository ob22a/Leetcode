class CustomStack {
public:
    int size;
    vector<int>s;
    CustomStack(int maxSize) {
        size=maxSize;
    }
    
    void push(int x) {
        if(s.size()<size){
            s.push_back(x);
        }
    }
    
    int pop() {
        if(s.empty()) return -1;
        int val=s.back();
        s.pop_back();
        return val;
    }
    
    void increment(int k, int val) {
        int i=0;
        while(i<k && i<s.size()){
            s[i]+=val;
            ++i;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */