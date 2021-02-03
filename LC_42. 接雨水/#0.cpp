//2020.09.13_#0_BestVotes

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1, maxLeft = 0, maxRight = 0, res = 0;
        
        while (left <= right) {
            if (height[left] <= height[right]) {
                
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                }
                else {
                    res = res + maxLeft - height[left];
                }
                
                left++;
            }
            else {
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                }
                else {
                    res = res + maxRight - height[right];
                }
                
                right--;
            }
        }
        
        return res;
    }
};

//BestVotes
/*

class Solution {
public:
    int trap(int A[], int n) {
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(A[left]<=A[right]){
                if(A[left]>=maxleft) maxleft=A[left];
                else res+=maxleft-A[left];
                left++;
            }
            else{
                if(A[right]>=maxright) maxright= A[right];
                else res+=maxright-A[right];
                right--;
            }
        }
        return res;
    }
};

*/