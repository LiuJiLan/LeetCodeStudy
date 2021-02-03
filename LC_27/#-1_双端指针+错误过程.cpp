//2020.09.29_#-1_双指针+错误过程

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0, r = (int)nums.size() - 1;
        
        if (r == 0 && nums[l] != val) {
            return 1;
        }
        
        while (l < r) {
            while (l <= r && nums[l] != val) {
                l++;
            }
            while (l < r && nums[r] == val) {
                r--;
            }
            
            if (l < r) {
                swap(nums[l], nums[r]);
            }
            
        }

        return l;
    }
};

/*
 输入：
 [2]
 3
 输出：
 []
 预期：
 [2]
 
 class Solution {
 public:
     int removeElement(vector<int>& nums, int val) {
         int l = 0, r = (int)nums.size() - 1;
         
         while (l < r) {
             while (l < r && nums[l] != val) {
                 l++;
             }
             while (l < r && nums[r] == val) {
                 r--;
             }
             
             swap(nums[l], nums[r]);
         }
         
         return l;
     }
 };

 */


/*
 输入：
 [2]
 3
 输出：
 []
 预期：
 [2]
 class Solution {
 public:
     int removeElement(vector<int>& nums, int val) {
         int l = 0, r = (int)nums.size() - 1;
         
         while (l < r) {
             while (l <= r && nums[l] != val) {
                 l++;
             }
             while (l < r && nums[r] == val) {
                 r--;
             }
             
             if (l < r) {
                 swap(nums[l], nums[r]);
             }
             
         }
            
         return l;
     }
 };
 */

/*
 超出时间限制
 //while (l <= r)造成的死循环
 class Solution {
 public:
     int removeElement(vector<int>& nums, int val) {
         int l = 0, r = (int)nums.size() - 1;
         
         while (l <= r) {
             while (l <= r && nums[l] != val) {
                 l++;
             }
             while (l < r && nums[r] == val) {
                 r--;
             }
             
             if (l < r) {
                 swap(nums[l], nums[r]);
             }
             
         }

         return l;
     }
 };
 */
