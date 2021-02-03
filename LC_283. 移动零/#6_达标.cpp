//2020.11.22_#6_达标

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) != 0) {
                swap(nums[i], nums[count++]);
            }
        }
        for (int i = count; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
};
