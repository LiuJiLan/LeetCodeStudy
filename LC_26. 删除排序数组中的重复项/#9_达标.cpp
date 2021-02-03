//2020.11.27_#9_达标

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for (int i = 0;i < nums.size(); i++) {
            if (count == 0 || nums[count - 1] != nums.at(i)) {
                nums[count++] = nums.at(i);
            }
        }
        return count;
    }
};
