class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> s;
        s.push(map<string, int>());

        int n = formula.size();
        int i = 0;

        while(i < n){
            if(formula[i] == '('){
                s.push(map<string, int>());
                ++i;
            }
            else if(formula[i] == ')'){
                map<string, int> temp = s.top();
                s.pop();
                ++i;

                string multiplier_buffer = "";

                while(i < n && isdigit(formula[i])){
                    multiplier_buffer += formula[i];
                    ++i;
                }

                int multiplier = multiplier_buffer.empty() ? 1 : stoi(multiplier_buffer);

                for(auto &[i, j]: temp) s.top()[i] += j*multiplier;
            }
            else{
                string atom = "";
                string num = "";

                atom += formula[i];
                ++i;

                while(i < n && formula[i] >= 'a' && formula[i] <= 'z'){
                    atom += formula[i];
                    ++i;
                }

                while(i < n && isdigit(formula[i])){
                    num += formula[i];
                    ++i;
                }

                s.top()[atom] += num.empty() ? 1 : stoi(num);
            }
        }

        string result = "";

        for(auto &[i, j]:s.top()){
            result += i;
            if(j > 1) result += to_string(j);
        }

        return result;
    }
};