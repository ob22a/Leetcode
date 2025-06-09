class StockSpanner {
public:
    vector<int> stk;
    StockSpanner() {

    }
    
    int next(int price) {
        int count=0;
        stk.push_back(price); 
        int idx=stk.size()-1;
        while(idx>=0 && stk[idx]<=price){
            --idx;
            ++count;
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */