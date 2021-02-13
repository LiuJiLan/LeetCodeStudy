//2021.02.13_#0_MyPerference

// 我更看好的方法.

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans = vector<int>();
        
        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i] > 0 ? nums[i] : -nums[i];
            if (nums[cur - 1] > 0) {
                nums[cur - 1] = -nums[cur - 1];
            }
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};
