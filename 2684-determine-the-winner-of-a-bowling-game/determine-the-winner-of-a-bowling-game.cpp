class Solution {
public:
    int findScore(vector<int>& player){
        int n=player.size();
        int ctr=0, score=0;

        vector<bool> isTwice(n,false);
        for(int i=0;i<n;++i){
            if(player[i]==10){
                if(i+1<n) isTwice[i+1]=true;
                if(i+2<n) isTwice[i+2]=true;
            }
        }

        for(int i=0;i<n;++i){
            score+=(isTwice[i])?2*player[i]:player[i];
        }

        return score;
    }
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1=findScore(player1),score2=findScore(player2);
        return (score1>score2)?1:(score2>score1)?2:0;
    }
};