class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);

        int i=str.size()-2;
        while(i>=0 && str[i]>=str[i+1]) --i;
        if(i<0) return -1;

        int j=str.size()-1;
        while(str[j]<=str[i]) --j;
        swap(str[j],str[i]);

        reverse(str.begin()+i+1,str.end());

        long long sol = stoll(str);
        return (sol>INT_MAX)?-1:sol;
    }
}; 