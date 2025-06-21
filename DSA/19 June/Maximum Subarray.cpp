class Solution {
public:
    int maxSubArray(vector<int>& nums){
        if(nums.size() == 1) return nums[0];

        int n = nums.size();
        int sum = INT_MIN, temp = 0;

        int i = 0;
        while(i < n){
            temp += nums[i];
            sum = max(sum, temp);

            //cout << "temp: " << temp << " sum: " << sum << endl;

            if(temp < 0) temp = 0;
            ++i;
        }

        return sum;
    }
};