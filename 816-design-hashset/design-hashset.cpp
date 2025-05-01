class MyHashSet {
public:
    vector<vector<int>> set{vector<vector<int>>(100)};
    MyHashSet() {
        
    }
    
    void add(int key) {
        set[key%100].push_back(key);
    }
    
    void remove(int key) {
        for(int i=0;i<set[key%100].size();++i){
            if(set[key%100][i]==key) set[key%100][i]=-1;
        }
    }
    
    bool contains(int key) {
        for(int num:set[key%100]){
            if(num==key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */