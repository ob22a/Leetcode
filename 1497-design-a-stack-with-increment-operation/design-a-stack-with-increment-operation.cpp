class CustomStack {
public:
    int size;
    vector<int>s,inc;
    CustomStack(int maxSize) {
        size=maxSize;
        inc.resize(maxSize);
    }
    
    void push(int x) {
        if(s.size()<size){
            s.push_back(x);
        }
    }
    
    int pop() {
        if(s.empty()) return -1;
        int i=s.size()-1;
        if(i>0) inc[i-1]+=inc[i];
        int val=inc[i]+s.back();
        s.pop_back();
        inc[i]=0;
        return val;
    }
    
    void increment(int k, int val) {
        int ind=min(k,int(s.size()))-1;
        if(ind>=0) inc[ind]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */