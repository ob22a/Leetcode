class BrowserHistory {
public:
    stack<string> currentPage,prevPage;
    BrowserHistory(string homepage) {
        currentPage.push(homepage);
    }
    
    void visit(string url) {
        prevPage={};
        currentPage.push(url);
    }
    
    string back(int steps) {
        int i=0;
        while(i<steps && !currentPage.empty()){
            prevPage.push(currentPage.top());
            currentPage.pop();
            ++i;
        }
        if(currentPage.empty()){
            currentPage.push(prevPage.top());
            prevPage.pop();
        }
        return currentPage.top();
    }
    
    string forward(int steps) {
        int i=0;
        while(i<steps && !prevPage.empty()){
            currentPage.push(prevPage.top());
            prevPage.pop();
            ++i;
        }

        return currentPage.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
