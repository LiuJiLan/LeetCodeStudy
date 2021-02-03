//2020.09.14_#4_不达标

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0 || nums[count-1] < nums[i]) {
                //count == 0保护了[] [x] 和 [x,x,x,x]类似的案例
                nums[count++] = nums[i];
            }
        }
        
        return count;
    }
};