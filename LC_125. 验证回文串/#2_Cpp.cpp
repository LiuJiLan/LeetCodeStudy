//2020.09.09

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size()-1; i < j; i++, j--) {
            
            while (!isalnum(s[i]) && i < j) {
                i++;
            }

            while (!isalnum(s[j]) && i < j) {
                j--;
            }

            //一定要记住忽略大小写
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
        }

        return true;

    }
};