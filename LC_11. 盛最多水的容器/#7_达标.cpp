//2020.11.01_#7_达标

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        
        for (int l = 0, r = (int) height.size() - 1; l < r;) {
            int h = min(height[l], height[r]);
            area = max(area, h * (r - l));
            if (l < r && height[l] <= h) {
                l++;
            }
            if (l < r && height[r] <= h) {
                r--;
            }
        }
        
        return area;
    }
};
