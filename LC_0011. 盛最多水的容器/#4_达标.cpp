//2020.09.06_#4_达标

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int h = min(height[i], height[j]);
        int s = h * (j - i);
        
        while (i < j) {
            int h = min(height[i], height[j]);
            
            while (i < j && height[i] <= h) {
                i++;    
            }
            while (i < j && height[j] <= h) {
                j--;    
            }
            
            h = min(height[i], height[j]);
            s = max(h * (j - i), s);
        }
        
        return s;
    }
};