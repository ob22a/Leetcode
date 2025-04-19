class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long M=mass;
        for(int m:asteroids){
            if(M<m) return false;
            M+=m;
        }
        return true;
    }
};