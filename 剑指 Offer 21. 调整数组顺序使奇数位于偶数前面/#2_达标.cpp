//2020.10.31_#2_达标

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        for (int s = 0, f = 0; f < nums.size(); f++) {
            if (nums[f] % 2 == 1) {
                swap(nums[f], nums[s++]);
            }
        }
        
        return nums;
    }
};

