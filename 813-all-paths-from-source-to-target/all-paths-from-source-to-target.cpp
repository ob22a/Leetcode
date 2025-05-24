class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        queue<vector<int>> paths;
        paths.push({0});
        while(!paths.empty()){
            vector<int> path=paths.front(); paths.pop();
            int idx=path.back();
            if(idx==graph.size()-1) result.push_back(path);
            else{
                for(int neighbour:graph[idx]){
                    path.push_back(neighbour);
                    paths.push(path);
                    path.pop_back();
                }
            }
        }
        return result;
    }
};