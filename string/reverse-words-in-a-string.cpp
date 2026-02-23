class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        string ans = "";
        for(int i =0; i<s.size(); i++){
            if(s[i]!= ' '){
                temp += s[i];
            }
            else{
                if(!temp.empty()){
                    if(!ans.empty())
                        ans = temp + " "+ ans;
                    
                        else
                        ans = temp;
                    temp = "";
                    }
                }
        } 
            
            if(!temp.empty()){
                if(!ans.empty())
                ans = temp + " "+ ans;
                else 
                ans = temp;
            }
            return ans;
        }
};