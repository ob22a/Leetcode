class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        vector<string> sol;
        vector<string> paths;

        auto bkt = [&](auto&& self, int idx, int parts){
            int partLeft = 4-parts;
            int remaining=n-idx;
            if(remaining<partLeft || remaining>partLeft*3) return;

            if(parts==4){
                if(idx==n){
                    string ipAdd;
                    for(int i=0;i<4;++i){
                        if(i>0) ipAdd+='.';
                        ipAdd+=paths[i];
                    }
                    sol.push_back(ipAdd);
                }
                return;
            }

            for(int length=1;length<4;++length){
                if(idx+length>n) break;
                string seg=s.substr(idx,length);

                if((length>1 && seg[0]=='0')||(stoi(seg)>255)) continue;
                paths.push_back(seg);
                self(self,idx+length,parts+1);
                paths.pop_back();
            }
        };

        bkt(bkt,0,0);
        return sol;
    }
};