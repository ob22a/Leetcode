class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> playerLost;
        for(int i=0;i<matches.size();++i){
            if(!playerLost.count(matches[i][0])) playerLost[matches[i][0]]=0;
            playerLost[matches[i][1]]--;
        }
        vector<int>allWin,oneLose;

        for(const auto& player:playerLost){
            if(player.second==0) allWin.push_back(player.first);
            else if(player.second==-1) oneLose.push_back(player.first);
        }

        sort(allWin.begin(),allWin.end());
        sort(oneLose.begin(),oneLose.end());
        return {allWin,oneLose};
    }
};