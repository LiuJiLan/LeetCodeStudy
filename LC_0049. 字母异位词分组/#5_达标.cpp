//2021.02.04_#5_达标

class Solution {
private:
    string hashFunction(string & str) {
        string hashKey = "";
        int hashTable[26] = {0};
        for (int i = 0; i < str.length(); i++) {
            hashTable[str.at(i) - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            hashKey += string('a' + i, hashTable[i]);
        }
        return hashKey;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hashTable
        = unordered_map<string, vector<string>>();
        for (int i = 0; i < strs.size(); i++) {
            string key = hashFunction(strs.at(i));
            if (hashTable.count(key) != 1) {
                hashTable[key] = vector<string>();
            }
            hashTable[key].push_back(strs.at(i));
        }
        for (auto item : hashTable) {
            ans.push_back(item.second);
        }
        return ans;
    }
};
