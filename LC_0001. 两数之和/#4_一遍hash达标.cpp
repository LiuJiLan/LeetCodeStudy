//2020.11.14_#4_一遍hash达标

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable = unordered_map<int, int>();
        vector<int> ans = vector<int>();
        
        for (int i = 0; i < nums.size(); i++) {
            if (hashTable.count(target - nums.at(i)) != 1) {
                hashTable[nums.at(i)] = i;
            } else {
                ans.push_back(hashTable[target - nums.at(i)]);
                ans.push_back(i);
                return ans;
            }
        }
        
        return ans;
    }
};
