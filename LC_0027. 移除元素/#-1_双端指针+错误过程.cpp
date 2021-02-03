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

#if 0

这题《#-1_双端指针+错误过程》的错误在于使用了错误的双端指针,这题应该使用同向快慢指针。

这也是LeetCode官方的第一种解法。
这题其实本质上与LeetCode#283题类似。
//Java
/*
public int removeElement(int[] nums, int val) {
    int i = 0;
    for (int j = 0; j < nums.length; j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}
*/

LeetCode官方的第二种解法就是双端指针
优势在于用右端的n(#-1中为r)来处理类似[2],val = 3的情况。
//Java
/*
public int removeElement(int[] nums, int val) {
    int i = 0;
    int n = nums.length;
    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1];
            // reduce array size by one
            n--;
        } else {
            i++;
        }
    }
    return n;
}
*/

#endif
