class Solution {
    void fast_io(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
public:
    int singleNumber(vector<int>& nums) {
        fast_io();
        int x = 0;
        for(int i = 0; i < nums.size(); ++i) x^=nums[i];
        return x;
    }
};