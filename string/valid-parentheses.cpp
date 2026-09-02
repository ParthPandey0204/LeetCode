class Solution {
public:
    bool isValid(string s) {
        stack<char>a;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                a.push(s[i]);
            }
        else{ 
            if(a.empty()) return false;
        char ch = a.top();
        a.pop();
        if(!((s[i] == ')' && ch == '(') || (s[i] == '}' && ch == '{') || (s[i] == ']' && ch == '[')))
         return false;
        }  
    }
    return a.empty();
    }
};