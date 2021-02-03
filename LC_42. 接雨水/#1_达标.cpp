//2020.09.13_#1_达标

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, ml = 0, mr = 0, ans = 0;
        
        while (l <= r) {
            if (height[l] <= height[r]) {
                if (height[l] >= ml) {
                    ml = height[l];
                }
                else {
                    ans += ml - height[l];
                }
                
                l++;
            }
            else {
                if (height[r] >= mr) {
                    mr = height[r];
                }
                else {
                    ans += mr - height[r];
                }
                
                r--;
            }
        }
        
        return ans;
    }
};