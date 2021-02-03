//2020.10.19_#0_优雅的BestVotes
//与BestVotes无区别,但是BestVotes真的很漂亮

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk = stack<char>();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(')');
            } else if (s[i] == '[') {
                stk.push(']');
            } else if (s[i] == '{') {
                stk.push('}');
            } else if (stk.empty() || stk.top() != s[i]) {
                return false;
            } else {
                stk.pop();
            }
        }
        return stk.empty();
    }
};


//BestVotes_Java
/*
 public boolean isValid(String s) {
     Stack<Character> stack = new Stack<Character>();
     for (char c : s.toCharArray()) {
         if (c == '(')
             stack.push(')');
         else if (c == '{')
             stack.push('}');
         else if (c == '[')
             stack.push(']');
         else if (stack.isEmpty() || stack.pop() != c)
             return false;
     }
     return stack.isEmpty();
 }
 */
