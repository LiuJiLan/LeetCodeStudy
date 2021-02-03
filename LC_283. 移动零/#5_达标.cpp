//2020.10.07_#5_达标

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s = 0;
        for (int f = 0; f < nums.size(); f++) {
            if (nums[f] != 0) {
                nums[s++] = nums[f];
            }
        }
        
        while (s < nums.size()) {
            nums[s++] = 0;
        }
    }
};
