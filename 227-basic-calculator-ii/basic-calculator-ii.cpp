class Solution {
public:
    int precedence(char c){
        if(c=='+' || c=='-') return 1;
        else if(c=='*' || c=='/') return 2;
        return 0;
    }
    string rpn(string infix) {
        string sign;
        string sol = "";
        int n = infix.size();
        for (int i = 0; i < n; ++i) {
            char c = infix[i];
            if (c == ' ') continue;

            if (isdigit(c)) {
                while (i < n && isdigit(infix[i])) {
                    sol.push_back(infix[i]);
                    i++;
                }
                sol.push_back(' ');
                i--;
            }
            else if(c == '(') {
                sign.push_back(c);
            }
            else if (c == ')') {
                while (!sign.empty() && sign.back() != '(') {
                    sol.push_back(sign.back());
                    sol.push_back(' ');
                    sign.pop_back();
                }
                if (!sign.empty() && sign.back() == '(')
                    sign.pop_back();
            }
            else {
                while (!sign.empty() && precedence(sign.back()) >= precedence(c)) {
                    sol.push_back(sign.back());
                    sol.push_back(' ');
                    sign.pop_back();
                }
                sign.push_back(c);
            }
        }
        while (!sign.empty()) {
            sol.push_back(sign.back());
            sol.push_back(' ');
            sign.pop_back();
        }
        return sol;
    }


    int evaluateRPN(string rpn) {
        stack<int> stk;
        int n = rpn.size();
        for (int i = 0; i < n; ) {
            if (rpn[i] == ' '){
                i++;
                continue;
            }

            if (isdigit(rpn[i])) {
                int val = 0;
                while (i < n && isdigit(rpn[i])) {
                    val = val * 10 + (rpn[i] - '0');
                    i++;
                }
                stk.push(val);
            }
            else {
                char c = rpn[i];
                i++;
                int num2 = stk.top(); stk.pop();
                int num1 = stk.top(); stk.pop();

                if(c == '+') stk.push(num1 + num2);
                else if(c == '-') stk.push(num1 - num2);
                else if(c == '*') stk.push(num1 * num2);
                else if(c == '/') stk.push(num1 / num2);
            }
        }
        return stk.top();
    }

    int calculate(string s) {
        return evaluateRPN(rpn(s));
    }
};