class Solution {
public:
        bool backspaceCompare(string s, string t) {
    return String(s) ==String(t);
}

string String(string str) {
    stack<char>s;
    
    for (char c : str) {
        if (c == '#' && !s.empty()) {
           s.pop();
        } else if (c != '#') {
           s.push(c);
        }
    }
    
    string res= "";
    while (!s.empty()) {
        res = s.top() + res;
        s.pop();
    }
    
    return res;
}
};