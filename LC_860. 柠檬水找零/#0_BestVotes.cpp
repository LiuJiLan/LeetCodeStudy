//2020.10.10_#0_BestVotes

class Solution {
private:
    int five, ten;
    
public:
    bool lemonadeChange(vector<int>& bills) {
        five = 0;
        ten = 0;
        
        for (int i = 0; i < bills.size(); i++) {
            switch (bills[i]) {
                case 5:
                    five++;
                    break;
                    
                case 10:
                    ten++;
                    five--;
                    break;
                    
                case 20:
                    if (ten > 0) {
                        ten--;
                        five--;
                    } else {
                        five -= 3;
                    }
                    
                default:
                    break;
            }
            
            if (five < 0) {
                return false;
            }
        }
        
        return true;
    }
};

//BestVotes
/*
 Intuition:
 When the customer gives us $20, we have two options:

 To give three $5 in return
 To give one $5 and one $10.
 On insight is that the second option (if possible) is always better than the first one.
 Because two $5 in hand is always better than one $10


 Explanation:
 Count the number of $5 and $10 in hand.

 if (customer pays with $5) five++;
 if (customer pays with $10) ten++, five--;
 if (customer pays with $20) ten--, five-- or five -= 3;

 Check if five is positive, otherwise return false.


 Time Complexity
 Time O(N) for one iteration
 Space O(1)


 C++:

     int lemonadeChange(vector<int> bills) {
         int five = 0, ten = 0;
         for (int i : bills) {
             if (i == 5) five++;
             else if (i == 10) five--, ten++;
             else if (ten > 0) ten--, five--;
             else five -= 3;
             if (five < 0) return false;
         }
         return true;
     }
 Java:

     public boolean lemonadeChange(int[] bills) {
         int five = 0, ten = 0;
         for (int i : bills) {
             if (i == 5) five++;
             else if (i == 10) {five--; ten++;}
             else if (ten > 0) {ten--; five--;}
             else five -= 3;
             if (five < 0) return false;
         }
         return true;
     }
 */



