class BrowserHistory {
    vector<string> v;
    int index = -1;
    int last_index = 0;
public:
    BrowserHistory(string homepage) {
        visit(homepage);
    }
    
    void visit(string url) {
        ++index;
        if(index >= v.size()) v.push_back(url);
        else v[index] = url;
        last_index = index;
    }
    
    string back(int steps) {
        index = max(0, index - steps);
        return v[index];
    }
    
    string forward(int steps) {
        index = min(last_index, index + steps);
        return v[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */