class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row=image.size(),col=image[0].size();
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

        stack<pair<int,int>> stk;
        stk.push({sr,sc});
        int init=image[sr][sc];
        image[sr][sc]=color;

        if(init!=color){
            while(!stk.empty()){
                auto[x,y]=stk.top(); stk.pop();
                for(auto& cor:dir){
                    int nx=x+cor[0],ny=y+cor[1];
                    if(nx>=0 && ny>=0 && nx<row && ny<col && image[nx][ny]==init){
                        image[nx][ny]=color;
                        stk.push({nx,ny});
                    }
                }
            }
        }

        return image;
    }
};