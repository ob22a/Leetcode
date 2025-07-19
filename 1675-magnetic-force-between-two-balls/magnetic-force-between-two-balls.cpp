class Solution {
public:
    bool isPossible(const vector<int>& position,const int& distance,const int& balls){
        int count=1,last=position[0];
        for(int pos:position){
            if(last+distance<=pos){
                last=pos;
                count++;
            }
            if(count==balls) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int l=1,r=position[n-1]-position[0];

        while(l<r){
            int mid=1+l+(r-l)/2; // In previous cases left and mid colided but here we want that with right
            if(!isPossible(position,mid,m)) r=mid-1;
            else l=mid;
        }
        
        return r;
    }
};