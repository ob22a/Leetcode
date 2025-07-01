class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int counter[101]={};
        for(int i=0;i<rounds.size()-1;++i){
            int cur=rounds[i];
            while(cur!=rounds[i+1]){
                counter[cur]++;
                cur= (cur%n)+1;
            }
        }
        counter[rounds.back()]++;
        
        int maxRounds=0;
        vector<int> sol;
        for(int i=1;i<=n;++i){
            if(counter[i]>maxRounds){
                sol.clear();
                maxRounds=counter[i];
                sol.emplace_back(i);
            }
            else if(counter[i]==maxRounds) sol.emplace_back(i);
        }
        return sol;
    }
};
