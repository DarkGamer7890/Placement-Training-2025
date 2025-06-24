class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2) return;

        int n = nums.size();
        int i = n - 1;

        while(i > 0 && nums[i - 1] >= nums[i]) --i;

        int j = i;
        int index = -1;
        int num = INT_MAX;

        while(i > 0 && j < n){
            if(nums[j] > nums[i - 1] && nums[j] < num){
                index = j;
                num = nums[j];
            }
            ++j;
        }

        // cout << "i:" << i << " j:" << j << " num:" << num;

        if(i > 0 && index >= 0) swap(nums[i - 1], nums[index]);

        sort(nums.begin() + i, nums.end());
    }
};