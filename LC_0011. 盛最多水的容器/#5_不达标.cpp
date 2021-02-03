//2020.10.07_#5_不达标
//变量用多了
//这题不是接雨水,不用储存ml,mr

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = (int)height.size() - 1, ml = height[l], mr = height[r];
        int h = min(ml, mr);
        int ans = h * (r - l);
        
        while (l < r) {
            while (l < r && height[l] <= h) {
                l++;
            }
            ml = height[l];
            
            while (l < r && height[r] <= h) {
                r--;
            }
            mr = height[r];
            
            h = min(ml, mr);
            ans = max(ans, h * (r - l));
            
        }

        return ans;
    }
};
