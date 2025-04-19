class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count=0;
        for(string operation:logs){
            if(operation=="./") continue;
            else if(operation=="../"){
                if(count>0) --count;
            }
            else ++count;
        }  
        return count; 
    }
};