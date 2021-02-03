//2020.10.14_#4_不达标_三次书写注意原因
//注意重写,因为原理不熟
//注意考虑大前提 到底是 l < r 还是 l <= r
//注意考虑大前提 到底是 ml <= mr 还是 height[l] <= height[r]

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) {
            return 0;
        }
        
        int area = 0, l = 0, r = (int) height.size() - 1;
        int ml = height[l], mr = height[r];
        
        while (l <= r) {
            if (ml <= mr) {
                if (height[l] >= ml) {
                    ml = height[l];
                } else {
                    area += ml - height[l];
                }
                
                l++;
            } else {
                if (height[r] >= mr) {
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

class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0, l = 0, r = (int) height.size() - 1;
        int ml = 0, mr = 0;
        
        while (l <= r) {
            if (ml <= mr) {
                if (height[l] >= ml) {
                    ml = height[l];
                } else {
                    area += ml - height[l];
                }
                
                l++;
            } else {
                if (height[r] >= mr) {
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

class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0, l = 0, r = (int) height.size() - 1;
        int ml = 0, mr = 0;
        
        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] >= ml) {
                    ml = height[l];
                } else {
                    area += ml - height[l];
                }
                
                l++;
            } else {
                if (height[r] >= mr) {
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
