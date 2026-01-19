class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});

        string sol ="";

        while(!pq.empty()){
            auto [cnt,chr] = pq.top(); pq.pop();
            int n = sol.size();

            if(n>=2 && sol[n-1]==chr && sol[n-2]==chr){
                if(pq.empty()) break;
                auto [cnt2, chr2] = pq.top(); pq.pop();
                sol+=chr2;
                if(--cnt2>0) pq.push({cnt2,chr2});
                pq.push({cnt,chr});
            } else{
                sol+=chr;
                if(--cnt>0) pq.push({cnt,chr});
            }
        }

        return sol;
    }
};