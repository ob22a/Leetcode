class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        vector<int> sol(temperatures.size());

        for(int i=temperatures.size()-1;i>=0;--i){
            while(!s.empty() && s.top().first<=temperatures[i]){
                s.pop();
            }
            if(s.empty()) sol[i]=0;
            else{
                sol[i]=s.top().second-i;
            } 
            s.push({temperatures[i],i});
        }
        return sol;
    }
};