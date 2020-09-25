//2020.09.21_#3_达标

class Solution {
private:
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;
            r--;
        }
    }
    
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;
        
        reverse(nums, 0, size-1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, size-1);
    }
};
