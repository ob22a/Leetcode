class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i=0,j=0;
        for(string s:commands){
            if(s=="UP") i=max(i-1,0);
            else if(s=="DOWN") i=min(n-1,i+1);
            else if(s=="LEFT") j=max(0,j-1);
            else if(s=="RIGHT") j=min(n-1,j+1);
        }
        return (i*n)+j;
    }
};