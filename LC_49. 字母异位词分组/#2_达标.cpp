//2020.10.07_#2_达标
//注意后期学会unordered_map的旧C遍历法

class Solution {
private:
    unordered_map<string, vector<string>> hash;
    
    void hashFunc(string str) {
        int smallHash[26] = {0};
        
        for (int i = 0; i < str.size(); i++) {
            smallHash[str[i] - 'a']++;
        }
        
        string hashKey = "";
        
        for (int i = 0; i < 26; i++) {
            hashKey += string(smallHash[i], i + 'a');
        }
        
        if (hash.count(hashKey) != 1) {
            vector<string> newVulue = vector<string>();
            hash[hashKey] = newVulue;
        }
        
        hash[hashKey].push_back(str);
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for (int i = 0; i < strs.size(); i++) {
            hashFunc(strs[i]);
        }
        
        vector<vector<string>> ans = vector<vector<string>>();
        
        for(auto item : hash) {
            ans.push_back(item.second);
        }
        
        return ans;
    }
};
