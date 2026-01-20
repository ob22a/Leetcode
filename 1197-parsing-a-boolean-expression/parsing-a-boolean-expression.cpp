class Solution {
public:
    void solve(stack<char>& op, stack<char>& val){
        bool result;
        char oper=op.top();
        if(oper=='&') result = true;
        else if(oper == '|') result = false;
        else if(oper=='!'){
            result = (val.top()=='t')?false:true;
            val.pop();
        }

        if(op.top() ==',') return;

        int n =val.size();

        if(op.top()!='!'){
            while(val.top()!='('){
                if(oper=='&'){
                    char v = val.top(); val.pop();
                    bool res = (v=='t');
                    result = result && res;
                } else if(oper=='|'){
                    char v = val.top(); val.pop();
                    bool res = (v=='t');
                    result =result || res;
                }
            }
        }

        val.pop(); //remove (
        val.push(result?'t':'f');
        op.pop(); //remove the operation it has been used up

        return ;
    }
    bool parseBoolExpr(string expression) {
        // simple rules 
        // when you find operation put it in a stack
        // when you find value put it in another stack
        // When you get open parenthesis put in stack with operations 
        // When you get closed parenthesis pop all till that open parenthesis 

        stack<char> op;
        stack<char> val;

        for(char c:expression){
            if(c=='t' || c=='f' || c=='(') val.push(c);
            else if(c==',') continue;
            else if(c!=')') op.push(c);
            else{
                solve(op,val);
            }
        }


        return val.top()=='t';
    }
};