class Solution {
    int ans(int a, int b, string i){
        if(i == "+") return a+b;
        else if(i == "-") return b-a;
        else if(i == "*") return a*b;
        return b/a;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n = tokens.size();
        for(int i = 0; i < n; ++i){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(ans(a, b, tokens[i]));
            } 
            else s.push(stoi(tokens[i]));
        }

        return s.top();
    }
};