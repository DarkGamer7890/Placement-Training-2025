class Solution {
  public:
    int findSingle(vector<int> &arr) {
        unordered_map<int, int> m;
        
        int n = arr.size();
        for(int i = 0; i < n; ++i) ++m[arr[i]];
        
        for(auto &i:m) if(i.second % 2) return i.first;
        
        return 0;
    }
};