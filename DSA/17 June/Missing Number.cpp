class Solution {
    void fast_io(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
public:
    int missingNumber(vector<int>& nums) {
        fast_io();
        int n = nums.size();
        int s = 0;
        for(int i = 0; i < n; ++i) s += nums[i];
        return n*(n+1)/2 - s;
    }
};