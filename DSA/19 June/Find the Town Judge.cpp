class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() == 0 && n == 1) return 1;
        else if(trust.size() == 0 && n > 1) return -1;

        vector<int> graph1(n + 1, 0);
        vector<int> graph2(n + 1, 0);

        for(auto &i:trust){
            ++graph1[i[0]];
            ++graph2[i[1]];
        }
        
        for(int i = 1; i <= n; ++i) if(!graph1[i] && graph2[i] == n - 1) return i;
        

        return -1;
    }
};