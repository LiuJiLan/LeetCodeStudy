//2020.09.21_#3_达标
//注意:
//l++的前提是height[l] < height[r],因为水的高度是由矮的那边决定的

class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0, l = 0, r = (int)height.size()-1, ml = 0, mr = 0;
        
        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] > ml) {
                    ml = height[l];
                }
                else {
                    area += ml - height[l];
                }
                
                l++;
            }
            else {
                if (height[r] > mr) {
                    mr = height[r];
                }
                else {
                    area += mr - height[r];
                }
                
                r--;
            }
        }
        
        return area;
    }
};
