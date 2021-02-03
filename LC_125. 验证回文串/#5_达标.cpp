//2020.11.20_#5_达标

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = (int) s.length() - 1;
        while (l < r) {
            while (l < r && !isalnum(s.at(l))) {
                l++;
            }
            while (l < r && !isalnum(s.at(r))) {
                r--;
            }
            if (tolower(s.at(l)) != tolower(s.at(r))) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
