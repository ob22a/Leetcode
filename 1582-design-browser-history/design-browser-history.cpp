class BrowserHistory {
public:
    vector<string> page;
    int index;
    BrowserHistory(string homepage) {
        page.clear();
        page.push_back(homepage);
        index=0;
    }
    
    void visit(string url) {
        int i=page.size()-1;
        while(i!=index){
            --i;
            page.pop_back();
        }
        ++index;
        page.push_back(url);
    }
    
    string back(int steps) {
        index=(index-steps)>0?index-steps:0;
        return page[index];
    }
    
    string forward(int steps) {
        index=(index+steps<page.size())?index+steps:page.size()-1;
        return page[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */