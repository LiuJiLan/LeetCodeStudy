//2020.09.16_#4_达标

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s = 0, f = 0;
        //s means slow, f means fast
        while (f < nums.size()) {
            if (nums[f] != 0) {
                nums[s++] = nums[f];
            }
            
            f++;
        }
        
        while (s < nums.size()) {
            nums[s++] = 0;
        }
    }
};