//2020.09.19_#2_两遍hash达标

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];
            
            if (hash.find(difference) != hash.end()) {
                ans = vector<int>({hash[difference], i});
                return ans;
            }
            
            hash[nums[i]] = i;
        }
        
        return ans;
    }
};
