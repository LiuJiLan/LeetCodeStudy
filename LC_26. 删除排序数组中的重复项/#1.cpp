//2020.09.13_#1

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        
        //本质上for (int i = 0; i < nums.size(); i++)是对for _ in nums的改写
        for (int i = 0; i < nums.size(); i++) {
            //count == 0 是防止||后的条件越界
            //nums[i] > nums[count-1]就是当发现有新的元素出现
			   //
            if (count == 0 || nums[i] > nums[count-1]) {
                nums[count++] = nums[i];
            }
        }
        
        return count;
    }
};

/*

int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (!i || n > nums[i-1])
            nums[i++] = n;
    return i;
}

*/

