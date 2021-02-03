//2020.09.19_#-1_自己数组模拟hash写法

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hashArray = vector<int>(26,0);
        
        for (int i = 0; i < s.size(); i++) {
            hashArray[s[i] - 'a']++;
        }
        
        for (int i = 0; i < t.size(); i++) {
            hashArray[t[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (hashArray[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};
