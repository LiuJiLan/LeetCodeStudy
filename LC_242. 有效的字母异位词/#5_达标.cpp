//2020.11.14_#5_达标

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        int hashTable[26] = {0};
        for (int i = 0; i < s.size(); i++) {
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
