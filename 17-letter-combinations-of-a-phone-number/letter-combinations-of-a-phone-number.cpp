class Solution {
public:
    vector<string> letters={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void backtrack(string digits,string res,vector<string>& sol,int idx){
        if(idx==digits.size()){
            sol.push_back(res);
            return;
        }

        string possible = letters[digits[idx]-'2'];
        for(char c:possible){
            res.push_back(c);
            backtrack(digits,res,sol,idx+1);
            res.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        vector<string> sol;
        string res="";
        backtrack(digits,res,sol,0);

        return sol;
    }
};
/*
"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
  0     1     2     3     4      5     6      7


235
res=""

possible = "abc"
c="a"
res="a"
	possible = "def"
	c="d"
	res="ad"
		possible = "jkl"
		c="j"
		res="adj"
			["adj"]
		c="k"
		res="adk"
			["adj","adk"]
		c="l"
		res="adl"
			["adj","adk","adl"]
            .
            .
            .
*/