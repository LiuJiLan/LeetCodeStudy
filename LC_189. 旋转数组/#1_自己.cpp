//2020.09.13_#1_自己

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size()-1);//反转整个数组
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size()-1);
    }
    
    void reverse(vector<int>& nums, int r, int l) {
        // r confess right , l confess left
        while (r < l) {
            int temp = nums[r];
            nums[r] = nums[l];
            nums[l] = temp;
            r++;
            l--;
        }
    }
};