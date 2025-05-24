class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;
        //Using array instead of hashing
        vector<vector<int>> adj(n);
        vector<bool> seen(n,false);

        for(int i=0;i<edges.size();++i){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        queue<int> nodes;
        nodes.push(source);
        seen[source]=true;

        while(!nodes.empty()){
            int val = nodes.front(); nodes.pop();
            if (val == destination) return true;
            for(int neighbour:adj[val]){
                if(!seen[neighbour]){
                    nodes.push(neighbour);
                    seen[neighbour]=true;
                }
            }
        }
        return false;
    }
};