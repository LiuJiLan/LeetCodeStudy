//2020.12.04_#1_自写最快

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) != val) {
                swap(nums[count++], nums[i]);
            }
        }
        return count;
    }
};
