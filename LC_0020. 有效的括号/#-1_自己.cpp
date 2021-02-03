//2020.10.19_#-1_自己
//与BestVotes无区别,但是BestVotes真的很漂亮

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            return false;
        }
        
        stack<char> stk = stack<char>();
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(')');
                continue;
            }
            if (s[i] == '[') {
                stk.push(']');
                continue;
            }
            if (s[i] == '{') {
                stk.push('}');
                continue;
            }
            
            if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (stk.empty()) {
                    return false;
                }
                if (s[i] != stk.top()) {
                    return false;
                }
                stk.pop();
            }
        }
        
        if (!stk.empty()) {
            return false;
        }
        
        return true;
    }
};
