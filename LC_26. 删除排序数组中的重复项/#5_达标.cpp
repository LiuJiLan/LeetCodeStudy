//2020.09.21_#5_达标

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[count-1] < nums[i]) {
                nums[count++] = nums[i];
            }
        }
        
        return count;
    }
};
