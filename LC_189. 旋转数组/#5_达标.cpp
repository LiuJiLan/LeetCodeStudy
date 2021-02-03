//2020.11.02_#5_达标

class Solution {
private:
    vector<int> * p_array;
    
    void reverse(int begin, int end) {
        end--;
        while (begin < end) {
            swap(p_array->at(begin++), p_array->at(end--));
        }
    }
    
public:
    void rotate(vector<int>& nums, int k) {
        p_array = & nums;
        k = k % nums.size();
        reverse(0, (int) nums.size());
        reverse(0, k);
        reverse(k, (int) nums.size());
    }
};
