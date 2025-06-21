class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int temp = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i]) ++temp;
            else{
                count = max(count, temp);
                temp = 0;
            }
        }
        if(temp > count) return temp;
        return count;
    }
};