class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;
        
        //Construct adjacenecy matrix
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();++i){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> nodes;
        unordered_set<int> seen;
        for(int node:adj[source]){
            nodes.push(node);
            seen.insert(node);
        }
        
        while(!nodes.empty()){
            int val = nodes.front(); nodes.pop();
            if(val==destination) return true;
            for(int node:adj[val]){
                if(!seen.count(node)) nodes.push(node);
                seen.insert(node);
            }
        }
        return false;
    }
};