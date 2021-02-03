//2020.09.13_#0_0ms最优Cpp

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {   
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            
            digits[i] = 0;
        }
        
        digits[0]=1;
        digits.push_back(0);
        
        return digits;
    }
};

//原始0ms范例
/*

class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        for (int i = digits.size()-1; i >= 0; i--)
        {
            digits[i] += 1;
            if (digits[i] > 9)
                digits[i] = 0;
            else
                return digits;
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};
*/