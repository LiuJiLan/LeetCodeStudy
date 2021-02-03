//2020.09.13_#-1_java改_非最优

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        
        for (int i = len - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            
            digits[i] = 0;
        }
        
        vector<int> newDigits(len+1);
        newDigits[0]=1;
        
        return newDigits;
    }
};

//BestVotes in Java
/*

public int[] plusOne(int[] digits) {
        
    int n = digits.length;
    for(int i=n-1; i>=0; i--) {
        if(digits[i] < 9) {
            digits[i]++;
            return digits;
        }
        
        digits[i] = 0;
    }
    
    int[] newNumber = new int [n+1];
    newNumber[0] = 1;
    
    return newNumber;
}

*/