//2020.09.19_#2_一遍hash达标

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];
            
            if (hash.find(difference) != hash.end() && hash[difference] != i) {
                ans = vector<int>({i, hash[difference]});
                return ans;
            }
        }
        
        return ans;
    }
};
