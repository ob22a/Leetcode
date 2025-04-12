class Solution {
public:
    int calPoints(vector<string>& operations) {
        int result=0;
        vector<int> record;
        for(string a:operations){
            if(a=="+")
                record.push_back(record[record.size()-1]+record[record.size()-2]);
            
            else if(a=="C") record.pop_back();
            else if(a=="D") record.push_back(2*record.back());
            else record.push_back(stoi(a));
        }
        for(int num:record){
            result+=num;
        }

        return result;
    }
};