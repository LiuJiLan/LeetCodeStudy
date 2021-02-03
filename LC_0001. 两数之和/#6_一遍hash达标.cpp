//2021.02.03_#6_一遍hash达标

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable = unordered_map<int, int>();
        vector<int> ans = vector<int>();
        
        for (int i = 0; i < nums.size(); i++) {
            if (hashTable.count(target - nums[i]) != 0) {
                ans.push_back(hashTable.at(target - nums[i]));
                ans.push_back(i);
                return ans;
            }
            hashTable[nums[i]] = i;
        }
        
        return ans;
    }
};

