class RecentCounter {
public:
    RecentCounter() {
        i=0;
    }
    
    int ping(int t) {
        requests.push_back(t);
        if(requests.size()==1) return 1;

        while(t-requests[i]>3000){
            ++i;
        }
        return requests.size()-i;
    }
private:
    vector<int> requests;
    int i;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
