//2021.02.13_#0_官方解

// 题设很巧妙, 如果范围是[0, n]那么这题不可能实现
// 因为要用取模的方式讨论0和n的区别是不现实的.
// 题目中是[1, n]可以映射到[0, n - 1]
// 将自身当作做一个hash表, 遇到了就+= n
// 但另一种方式却更好用, 直接将见过的值赋“-”号

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans = vector<int>();
        
        int n = (int) nums.size();
        for (int i = 0; i < n; i++) {
            nums[(nums[i] - 1) % n] += n;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};

#if 0
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans = vector<int>();
        
        int n = (int) nums.size();  // 因为多次使用,所以要提前取出
        for (int i = 0; i < n; i++) {
            nums[nums[i] % n - 1] += n;
            // 不能这么写, 这样写会造成0的情况
            // 但会导致映射时n和1都映射到0
            // 要提前-1
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};
#endif
