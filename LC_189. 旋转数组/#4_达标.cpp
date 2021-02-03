//2020.10.14_#4_达标

class Solution {
private:
    void reverse(vector<int>& nums, int left, int right) {
        //This time include the left index, without right index.
        right--;
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
    
public:
    void rotate(vector<int>& nums, int k) {
        int size = (int) nums.size();
        k = k % size;
        
        reverse(nums, 0, size);
        reverse(nums, 0, k);
        reverse(nums, k, size);
    }
};
