//2020.10.12_#0_自己快慢指针

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
