//2020.11.27_#6_达标

class Solution {
private:
    void reverse(vector<int>& nums, int begin, int end) {
        end--;
        while (begin < end) {
            swap(nums[begin], nums[end]);
            begin++;
            end--;
        }
    }
    
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums, 0, (int) nums.size());
        reverse(nums, 0, k);
        reverse(nums, k, (int) nums.size());
    }
};
