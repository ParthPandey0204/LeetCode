class Solution {
public:
    string reverseWords(string s) {
        // Remove leading spaces
        removeLeadingSpaces(s);
        
        string temp = "";
        string ans = "";
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                temp += s[i];
            } else if (s[i] == ' ') {
                if (!temp.empty()) {
                    if (!ans.empty()) {
                        ans = temp + " " + ans;
                    } else {
                        ans = temp;
                    }
                    temp = "";
                }
            }
        }
        
        if (!temp.empty()) {
            if (!ans.empty()) {
                ans = temp + " " + ans;
            } else {
                ans = temp;
            }
        }
        
        return ans;
    }

private:
    void removeLeadingSpaces(string& s) {
        size_t start = s.find_first_not_of(' ');
        if (start != string::npos) {
            s = s.substr(start);
        } else {
            s = ""; // If all spaces, return an empty string
        }
    }
};

