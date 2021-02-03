//2021.01.26_#7_改进

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) != 0) {
                nums[count++] = nums[i];
            }
        }
        for (int i = count; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
