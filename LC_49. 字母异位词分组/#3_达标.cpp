//2020.11.01_#3_达标

class Solution {
private:
    
    string hashFunc(string str) {
        int hashTable[26] = {0};
        string hashStr = "";
        for (int i = 0; i < str.size(); i++) {
            hashTable[str.at(i) - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            hashStr += string(hashTable[i], i + 'a');
        }
        return hashStr;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res = vector<vector<string>>();
        unordered_map<string, vector<string>> hash = unordered_map<string, vector<string>>();
        
        for (int i = 0; i < strs.size(); i++) {
            string strHashKey = hashFunc(strs.at(i));
            if (hash.count(strHashKey) == 1) {
                hash[strHashKey].push_back(strs.at(i));
            } else {
                hash[strHashKey] = vector<string>();
                hash[strHashKey].push_back(strs.at(i));
            }
        }
        
        for (auto item : hash) {
            res.push_back(item.second);
        }
        
        return res;
    }
};
