//2020.10.29_#3_一遍hash达标

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash = unordered_map<int, int>();
        vector<int> res = vector<int>();
        
        for (int i = 0; i < nums.size(); i++) {
            if(hash.count(target - nums[i])) {
                res.push_back(hash[target - nums[i]]);
                res.push_back(i);
                return res;
            } else {
                hash[nums[i]] = i;
            }
        }
        
        return res;
    }
};
