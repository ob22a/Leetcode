class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,vector<int>> words;
        for(int i=0;i<list1.size();++i) words[list1[i]].push_back(i);
        for(int i=0;i<list2.size();++i) words[list2[i]].push_back(i);
        int sum=INT_MAX;
        vector<string> sol;
        for(const auto& [word,indices]:words){
            if(indices.size()>1){
                int val=0;
                for(int idx:indices) val+=idx;
                if(val<sum){
                    sol.clear();
                    sum=val;
                    sol.push_back(word);
                }
                else if(val==sum) sol.push_back(word);
            } 
        }
        return sol;
    }
};