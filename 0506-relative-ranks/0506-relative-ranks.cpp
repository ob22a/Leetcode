class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        //Find the largest number
        int maximum=0;
        for(int num:score) maximum=max(maximum,num);
        
        // Create a vector of size maximum+1 to sort
        vector<string> sorted(maximum+1);
        for(int num:score) sorted[num]="Pending";

        //Add the actual rank by iterating from the back
        int rank=1;
        for(int i=maximum;i>=0;--i){
            if(sorted[i]=="Pending"){
                if(rank<=3){
                if(rank==1) sorted[i]="Gold Medal";
                else if(rank==2) sorted[i]="Silver Medal";
                else sorted[i]="Bronze Medal";
            }
            else sorted[i]=to_string(rank);
            ++rank;
            }
        }
        
        //Fill the vector sol with the rank in sorted
        vector<string> sol;
        for(int num:score) sol.push_back(sorted[num]);
        return sol;
    }
};