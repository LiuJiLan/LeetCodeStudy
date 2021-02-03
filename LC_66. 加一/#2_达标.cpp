//2020.09.14_#2_达标
//利用digits[i] < 9可以解决绝大部分情况,除了999之类的

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        
        while(i >= 0) {
            if (digits[i] < 9) {
                digits[i]++;
                
                return digits;
            }
            
            digits[i] = 0;
            i--;
        }
        
        digits[0] = 1;
        digits.push_back(0);
        
        return digits;
    }
};