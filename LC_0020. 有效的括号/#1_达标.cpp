//2021.01.30_#1_达标

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk = stack<char>();
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(')');
            } else if (s[i] == '[') {
                stk.push(']');
            } else if (s[i] == '{') {
                stk.push('}');
            } else if (!stk.empty() && stk.top() == s[i]) {
                stk.pop();
            } else {
                return false;
            }
        }
        return stk.empty();
    }
};
