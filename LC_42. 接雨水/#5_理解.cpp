//2020.10.19_#5_理解

class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0, l = 0, r = (int) height.size() - 1, ml = 0, mr = 0;
        
        while (l < r) {
            if (height[l] < height[r]) {
                //为什么不是ml < mr,而是height[l] < height[r]
                //其实比较的是动态化的ml与mr
                //但如果想一遍遍历完,ml与mr就不能做到时时更新
                //height[l] < height[r]本质上在移动指针的时候,
                //例:如果左比右小,就是移动左指针,事实上这个时候
                //height[r]停留的位置就是mr的最大值
                //当这个平衡被打破时,mr会得到更新,
                //如果下一个height[l] < mr 或者说是 height[r]
                //则会继续。
                //反之亦然。
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
