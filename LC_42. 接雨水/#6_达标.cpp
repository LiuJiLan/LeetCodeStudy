//2020.11.01_#6_达标

class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0, l = 0, r = (int) height.size() - 1, ml = 0, mr = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                if (ml <= height[l]) {
                    ml = height[l];
                } else {
                    area += ml - height[l];
                }
                l++;
            } else {
                if (mr <= height[r]) {
                    mr = height[r];
                } else {
                    area += mr - height[r];
                }
                r--;
            }
        }
        return area;
    }
};
