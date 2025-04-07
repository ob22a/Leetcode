class Solution {
public:
    string intToRoman(int num) {
        string romanNumber="";
        
        vector<tuple<string,int>> romInt={{"I",1},{"IV",4},{"V",5},{"IX",9},{"X",10},{"XL",40},{"L",50},{"XC",90},{"C",100},{"CD",400},{"D",500},{"CM",900},{"M",1000}};
        
        int bestInd=romInt.size()-1;//index of the last tuple in the vector
        while(num>0){
            auto [roman,val]=romInt[bestInd];
            if(num<val){
                --bestInd;
                continue;
            }
            num-=val;
            romanNumber+=roman;
        }
        return romanNumber;
    }
};