//2021.01.31_#9_达标

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = (int) height.size() - 1;
        int area = 0;
        
        while (l < r) {
            int h = min(height[l], height[r]);
            area = max(h * (r - l), area);
            while (l < r && height[l] <= h) {
                l++;
            }
            while (l < r && height[r] <= h) {
                r--;
            }
        }
        
        return area;
    }
};
