//2020.09.20_#0_官方解法
//注意后期学会unordered_map的旧C遍历法

class Solution {
private:
    string returnHash(string str) {
        int counter[26] = {0};
        string hashString;

        for (int i = 0; i < str.size(); i++) {
            counter[str[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            hashString += string(counter[i], i + 'a');
        }

        return hashString;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;

        for (int i = 0; i < strs.size(); i++) {
            dict[returnHash(strs[i])].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        //不会使用旧C的遍历来遍历Hash
        //找大佬问一下
        for (auto object : dict) {
            ans.push_back(object.second);
        }
        
        return ans;
    }
};


//BestVotes_Cpp
//实际上跟我的#-1的想法已经很类似了
/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            mp[strSort(s)].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) {
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
private:
    string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
        //string(counter[c], c + 'a');是string的构造函数
        //string(n, c);构造一个n个c的string
        //+是操作符重载
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};
*/
