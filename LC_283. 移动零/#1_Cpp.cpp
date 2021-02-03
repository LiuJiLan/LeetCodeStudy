//2020.09.09

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j = 0;
        
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }
        
        for (; j < nums.size(); j++) {
            nums[j] = 0;
        }
        
    }
};


//原题
/*

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
    }
};

*/

//Most Vote
/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        // move all the nonzero elements advance
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};
*/