class BrowserHistory {
public:
    stack<string> current,prev;
    BrowserHistory(string homepage) {
        current.push(homepage);
    }
    
    void visit(string url) {
        prev={};
        current.push(url);
    }
    
    string back(int steps) {
        for(int i=0;i<steps;++i){
            if(!current.empty()){
                prev.push(current.top());
                current.pop();
            }
            else break;
        }
        if(current.empty()){
            current.push(prev.top());
            prev.pop();
        }
        return current.top();
    }
    
    string forward(int steps) {
        for(int i=0;i<steps;++i){
            if(prev.empty()) break;
            current.push(prev.top());
            prev.pop();
        }
        return current.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */