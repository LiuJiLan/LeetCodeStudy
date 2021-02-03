//2020.12.08_#5_一遍hash达标

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable = unordered_map<int, int>();
        vector<int> ans = vector<int>();
        
        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums.at(i);
            
            if (hashTable.count(difference) == 1) {
                ans.push_back(hashTable.at(difference));
                ans.push_back(i);
                return ans;
            }
            
            hashTable[nums.at(i)] = i;
        }
        
        return ans;
    }
};
