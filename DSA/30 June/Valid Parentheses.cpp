class Solution {
public:
    bool isValid(string s) {
        int length = s.size();
        if(length % 2 != 0) return false;

        stack<char> b;
        for(int i = 0; i < length; ++i){
            char c = s[i];
            if(c == '(' || c == '{' || c == '[') b.push(c);
            
            else if(c == ')' || c == '}' || c == ']'){
                if(b.empty() || !check(b.top(), c)) return false;
                b.pop();
            }
        }

        return b.empty();
    }

private:
    bool check(char c, char c1){
        if(c == '(' && c1 == ')') return true;
        else if(c == '[' && c1 == ']') return true;
        else if(c == '{' && c1 == '}') return true;
        else return false;
    }
};