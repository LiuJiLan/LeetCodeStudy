//2020.09.13_#-1_自己的双指针解法

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int i = 0, j = 0;
        
        while (j < nums.size()) {
            //error:(nums[i] == nums[j] && j < nums.size())
            //当j == nums.size()会先做一次nums[i] == nums[j]导致数组越界
            
            while (j < nums.size() && nums[i] == nums[j]) {
                j++;
            }
            
            if (j < nums.size()) {
                i++;
                nums[i] = nums[j];
            }   
            
            
        }
        
        return ++i;//return index i + 1 for length
        
    }
};