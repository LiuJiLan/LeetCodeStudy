//2020.10.16_#1_达标

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int s = 0;
        for (int f = 0; f < nums.size(); f++) {
            if (nums[f] % 2 == 1) {
                swap(nums[s++], nums[f]);
            }
        }
        
        return nums;
    }
};

