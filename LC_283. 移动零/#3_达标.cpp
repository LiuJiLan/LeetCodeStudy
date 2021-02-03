//2020.09.13_#3_达标
//注意nums[i] != 0，题目中元素可能为负

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        
        for (; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        
        while (j < nums.size()) {
            nums[j++] = 0;
        }
    }
};