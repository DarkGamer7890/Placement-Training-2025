class Solution {
    void func(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        func();
        int min_l = INT_MAX;
        int count = 0;
        int left = 0;
        for(int i = 0; i < nums.size(); ++i){
            count += nums[i];
            while(count >= target) {
                min_l = min(min_l, i-left+1);
                count -= nums[left];
                ++left;
            }
        }
        return min_l == INT_MAX ? 0 : min_l;
    }
};