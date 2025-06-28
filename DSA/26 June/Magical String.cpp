class Solution {
public:
    int magicalString(int n) {
        if(n <= 3) return 1;

        int result = 1;
        int index = 2;
        bool flag = true;
        string s = "122";

        while(s.size() < n){
            int i = s[index] - '0';
            char c = (flag) ? '1' : '2';

            while(i > 0){
                s += c;
                if(c - '0' == 1) ++result;

                if(s.size() == n) return result;
                --i;
            }
            flag = !flag;
            ++index;
        }
        
        return result;
    }
};