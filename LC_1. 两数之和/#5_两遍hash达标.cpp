//2020.12.08_#5_两遍hash达标

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable = unordered_map<int, int>();
        vector<int> ans = vector<int>();
        
        for (int i = 0; i < nums.size(); i++) {
            hashTable[nums.at(i)] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (hashTable.count(target - nums.at(i)) == 1 && hashTable.at(target - nums.at(i)) != i) {
                ans.push_back(i);
                ans.push_back(hashTable.at(target - nums.at(i)));
                return ans;
            }
        }
        
        return ans;
    }
};


#if 0
//注意错误: 另一个index不能是其本身
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable = unordered_map<int, int>();
        vector<int> ans = vector<int>();
        
        for (int i = 0; i < nums.size(); i++) {
            hashTable[nums.at(i)] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            
            if (hashTable.count(target - nums.at(i)) == 1) {
                ans.push_back(i);
                ans.push_back(hashTable.at(target - nums.at(i)));
                return ans;
            }
        }
        
        return ans;
    }
};
#endif
