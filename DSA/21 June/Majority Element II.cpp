class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() == 1) return nums;

        vector<int> result;
        int n = nums.size();

        int first = nums[0], count1 = 0;
        int second = nums[1], count2 = 0;

        for(int i = 0; i < n; ++i){
            if(nums[i] == first) ++count1;

            else if(nums[i] == second) ++count2;

            else if(!count1){
                first = nums[i];
                count1 = 1;
            }

            else if(!count2){
                second = nums[i];
                count2 = 1;
            }

            else{
                --count1;
                --count2;
            }
        }

        count1 = 0, count2 = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] == first) ++count1;
            else if(nums[i] == second) ++count2;
        }

        if(count1 > n / 3) result.push_back(first);
        if(count2 > n / 3) result.push_back(second);

        return result;
    }
};