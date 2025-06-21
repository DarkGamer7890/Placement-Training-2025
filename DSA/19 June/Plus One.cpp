class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        vector<int> result;
        int carry = 1;
        for(int i = 0; i < digits.size(); ++i){
            int num = carry + digits[i];
            result.push_back(num % 10);
            carry = num/10;
        }
        if(carry) result.push_back(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};