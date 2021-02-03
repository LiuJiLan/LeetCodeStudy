
"""
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





def isPalindrome(num):
    s = list(num)
    l, r = 0, len(s)-1
    while l < r:
        while l < r and not s[l].isalnum():
            l += 1
        while l <r and not s[r].isalnum():
            r -= 1
        if s[l].lower() != s[r].lower():
            return False
        l +=1; r -= 1
    return True
    """


