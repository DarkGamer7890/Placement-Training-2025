class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0) ++cnt_0;
            else if(nums[i] == 1) ++cnt_1;
            else ++cnt_2;
        }

        int i = 0;
        while(cnt_0--){
            nums[i] = 0;
            ++i;
        }

        while(cnt_1--){
            nums[i] = 1;
            ++i;
        }

        while(cnt_2--){
            nums[i] = 2;
            ++i;
        }
    }
};