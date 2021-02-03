//2020.10.07_#4达标
//注意错误来源(l < r && !isalnum(s[index]))
//否则会引起越界

class Solution {
public:
    bool isPalindrome(string s) {
        for (int l = 0, r = (int) s.size() - 1; l < r; l++, r--) {
            while (l < r && !isalnum(s[l])) {
                l++;
            }
            while (l < r && !isalnum(s[r])) {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
        }
        
        return true;
    }
};
