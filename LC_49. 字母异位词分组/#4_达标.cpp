//2020.11.22_#4_达标

class Solution {
private:
    string hashFunc(string str) {
        int hashTable[26] = {0};
        string hashKey = "";
        for (int i = 0; i < str.length(); i++) {
            hashTable[str.at(i) - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            hashKey += string(hashTable[i], i + 'a');
        }
        return hashKey;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashTable = unordered_map<string, vector<string>>();
        vector<vector<string>> result = vector<vector<string>>();
        for (int i = 0; i < strs.size(); i++) {
            string key = hashFunc(strs.at(i));
            if (hashTable.count(key) != 1) {
                hashTable[key] = vector<string>();
            }
            hashTable[key].push_back(strs.at(i));
        }
        for (auto item : hashTable) {
            result.push_back(item.second);
        }
        return result;
    }
};
