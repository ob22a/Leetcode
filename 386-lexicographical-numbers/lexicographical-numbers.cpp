class Solution {
public:
    void dfs(int cur,int n,vector<int>& sol){
        if(cur>n) return;
        sol.push_back(cur);
        for(int i=0;i<10;++i){
            int next=cur*10+i;
            if(next>n) break;
            dfs(next,n,sol);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> sol;
        for(int i=1;i<10;++i){
            dfs(i,n,sol);
        }
        return sol;
    }
};