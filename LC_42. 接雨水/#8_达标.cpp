//2020.12.08_#8_达标

//注意大条件是(height[l] <= height[r])
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = (int) height.size() - 1, ml = 0, mr = 0, area = 0;
        
        while (l < r) {
            if (height[l] <= height[r]) {
                if (ml < height[l]) {
                    ml = height[l];
                } else {
                    area += ml - height[l];
                }
                l++;
            } else {
                if (mr < height[r]) {
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

#if 0
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = (int) height.size() - 1, ml = 0, mr = 0, area = 0;
        
        while (l < r) {
            if (ml <= mr) {
                if (ml < height[l]) {
                    ml = height[l];
                } else {
                    area += ml - height[l];
                }
                l++;
            } else {
                if (mr < height[r]) {
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
#endif
