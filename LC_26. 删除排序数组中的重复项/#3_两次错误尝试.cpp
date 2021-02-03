//2020.09.14_#3_两次错误尝试


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s = 0, f = 0;
        //s to slow, f to fast
        
        while (s == 0 || f < nums.size()) {
            if (nums[f] > nums[s]) {
                nums[++s] = nums[f];
            }
            f++;
        }
        
        return ++s;
        
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[count] < nums[i]) {
                nums[++count] = nums[i];
            }
        }
        
        return ++count;
    }
};