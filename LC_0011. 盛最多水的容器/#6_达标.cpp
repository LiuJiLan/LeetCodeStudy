//2020.10.07_#6_达标

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = (int) height.size() - 1;
        int h = min(height[l], height[r]);
        int ans = h * (r - l);
        
        while (l < r) {
            while (l < r && height[l] <= h) {
                l++;
            }
            while (l < r && height[r] <= h) {
                r--;
            }
            h = min(height[l], height[r]);
            ans = max(ans, h * (r - l));
        }
        
        return ans;
    }
};
