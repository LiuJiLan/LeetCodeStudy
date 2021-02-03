//2020.11.27_#6_达标

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = (int) digits.size() - 1; i >= 0; i--) {
            if (digits.at(i) < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};
