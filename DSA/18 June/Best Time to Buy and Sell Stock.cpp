class Solution {
    void FAST_IO(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

public:
    int maxProfit(vector<int>& prices) {
        FAST_IO();
        
        int initial = prices[0];
        int max_profit = 0;

        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] < initial) initial = prices[i];
            else max_profit = max(max_profit, prices[i] - initial);
        }

        return max_profit;
    }
};