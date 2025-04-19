class ProductOfNumbers {
public:
    vector<int>prefix;
    int size=0;
    ProductOfNumbers() {
        prefix.push_back(1);
    }
    
    void add(int num) {
        ++size;
        if(num==0){
            prefix.clear();
            prefix.push_back(1);
            size=0;
        }
        else prefix.push_back(prefix.back()*num);
    }
    
    int getProduct(int k) {
        if(k>size) return 0;
        return prefix.back()/prefix[size-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */