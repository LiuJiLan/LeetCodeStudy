//2020.12.08_#6_达标

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        int hashTable[26] = {0};
        
        for (int i = 0; i < s.length(); i++) {
            hashTable[s.at(i) - 'a']++;
            hashTable[t.at(i) - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (hashTable[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};
