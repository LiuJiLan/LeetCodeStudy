//2020.09.20_#-2_hash套娃编译失败

class Solution {
private:
    vector<int> returnHash(string str) {
        vector<int> hash = vector<int>(26, 0);
        
        for (int i = 0; i < str.size(); i++) {
            hash[str[i] - 'a'];
        }
        
        return hash;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map< vector<int>, vector<string> > dict;
        vector<vector<int>> keys;
        vector<vector<string>> ans;
        
        for (int i = 0; i < strs.size(); i++) {
            vector<int> curHash = returnHash(strs[i]);
            
            if (dict.find(curHash) == dict.end()) {
                keys.push_back(curHash);
            }
            
            dict[curHash] = dict[curHash].push_back(strs[i]);
        }
        
        for (int i = 0; i < keys.size(); i++) {
            ans.push_back(dict[keys[i]]);
        }
        
        return ans;
    }
};
