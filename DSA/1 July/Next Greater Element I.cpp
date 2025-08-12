// Method 1

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> result;

        unordered_map<int, int> m;

        for(int i = 0; i < n2; ++i){
            if(i == n2 - 1) m[nums2[i]] = -1;

            int j = i + 1;
            while(j < n2){
                if(nums2[j] > nums2[i]){
                    m[nums2[i]] = nums2[j];
                    break;
                }
                ++j;
            }

            if(j == n2) m[nums2[i]] = -1;
        }

        for(int i = 0; i < n1; ++i) result.push_back(m[nums1[i]]);

        return result;
    }
};



// Method 2

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        unordered_map<int, int> m;
        stack<int> s;

        for(int i = n2 - 1; i >= 0; --i){     // as last number always has -1
            while(!s.empty() && s.top() < nums2[i]) s.pop();

            m[nums2[i]] = s.empty() ? -1 : s.top();

            s.push(nums2[i]);
        } 

        vector<int> result;
        for(auto &i:nums1) result.push_back(m[i]);

        return result;
    }
};