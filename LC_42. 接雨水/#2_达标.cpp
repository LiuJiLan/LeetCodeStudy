//2020.09.14_#2_达标

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, ml = 0, mr = 0, v = 0;
        
        while (l < r) {
            if (height[l] <= height[r]) {
                if (ml < height[l]) {
                    ml =  height[l];
                }
                else {
                    v += ml - height[l];
                }
            
                l++;
            }
            else {
                if (mr < height[r]) {
                    mr =  height[r];
                }
                else {
                    v += mr - height[r];
                }
            
                r--;
            }
        }
        
        return v;
    }
};