//2020.10.15_#7_达标

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s = 0;
        
        for (int f = 0; f < nums.size(); f++) {
            if (s == 0 || nums[f] != nums[s - 1]) {
                nums[s++] = nums[f];
            }
        }
        
        return s;
    }
};
