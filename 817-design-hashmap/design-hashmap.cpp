class MyHashMap {
public:
    vector<vector<pair<int,int>>> hashMap{vector<vector<pair<int,int>>>(100)};
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        auto& bucket=hashMap[key%100];
        for(auto& p:bucket){
            if(key==p.first){
                p.second=value;
                return ;
            } 
        }
        bucket.push_back({key,value});
    }
    
    int get(int key) {
        for(const auto& p:hashMap[key%100]){
            if(p.first==key) return p.second;
        }
        return -1;
    }
    
    void remove(int key) {
        for(auto it=hashMap[key%100].begin();it!=hashMap[key%100].end();++it){
            if(it->first==key){
                hashMap[key%100].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */