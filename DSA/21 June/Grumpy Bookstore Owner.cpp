class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int c = customers.size();
        
        int satisfied = 0;
        int count = 0;

        for(int i = 0; i < minutes; ++i){
            if(!grumpy[i]) satisfied += customers[i];
            else count += customers[i];
        }

        int max_count = count;
        for(int i = minutes; i < c; ++i){

            if(!grumpy[i]) satisfied += customers[i];
            else count += customers[i];
            if(grumpy[i - minutes]) count -= customers[i - minutes];

            max_count = max(max_count, count);
        }

        return max_count + satisfied;
    }
};