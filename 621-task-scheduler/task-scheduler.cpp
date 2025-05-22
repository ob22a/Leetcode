class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*  1st Observation 
        The tasks with higher frequency must come first 
        Take AAB n=3
        if B comes first it becomes B A idle idle idle A ans:5
        if A came first it becomes A B idle idle A ans: 4
        */
        unordered_map<char,int> freq;
        for(char c:tasks) freq[c]++;

        /*  2nd Observation 
        During cooldown we store the delayed task in a queue.
        This allows the first delayed task to be used when its time comes 
        it is a tuple of freq and nextTime 
        */
        
        priority_queue<pair<int,char>> sorted; //count,idx
        for(const auto& p:freq) sorted.push({p.second,p.first});
        queue<pair<int,pair<int,char>>> cooldown;

        int time=0;

        while(!sorted.empty() || !cooldown.empty()){
            ++time;
            if(!cooldown.empty() && cooldown.front().first==time){
                sorted.push(cooldown.front().second);
                cooldown.pop();
            }
            if(!sorted.empty()){
                auto [count,ch]=sorted.top();
                sorted.pop();
                if(count>1) cooldown.push({time+n+1,{count-1,ch}});
            }
        }
        return time;
    }
};