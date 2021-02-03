//2020.11.16_#3_达标

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) {
                swap(nums[count++], nums[i]);
            }
        }
        return nums;
    }
};
