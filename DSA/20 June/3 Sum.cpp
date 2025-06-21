class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int size = nums.size();
        sort(nums.begin(), nums.end());
        if(size < 3) return {};

        vector<vector<int>> result;
        for(int i = 0; i < size - 2; ++i){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            if(nums[i] > 0) break;
            int j = i + 1;
            int k = size - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    result.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j+1]) ++j;
                    while(j < k && nums[k] == nums[k-1]) --k;
                    ++j;
                    --k;
                } 
                else if(sum < 0){
                    ++j;
                } 
                else{
                    --k;
                }
            }
        }
        return result;
    }
};