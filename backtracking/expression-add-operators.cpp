class Solution {
public:
    vector<string> result;
    string path;
    
    void dfs(const string& num, int target, int pos, 
             long long currVal, long long prevVal) {
        
        if (pos == num.size()) {
            if (currVal == target) {
                result.push_back(path);
            }
            return;
        }
        
        long long number = 0;
        int len = path.size();  
        
        for (int i = pos; i < num.size(); i++) {
            
            if (i > pos && num[pos] == '0') break;
            
            number = number * 10 + (num[i] - '0');
            
            if (pos == 0) {

                path += to_string(number);
                dfs(num, target, i + 1, number, number);
                path.resize(len);  
            } else {

                path += "+" + to_string(number);
                dfs(num, target, i + 1, currVal + number, number);
                path.resize(len);

                path += "-" + to_string(number);
                dfs(num, target, i + 1, currVal - number, -number);
                path.resize(len);
                
                path += "*" + to_string(number);
                dfs(num, target, i + 1,
                    currVal - prevVal + prevVal * number,
                    prevVal * number);
                path.resize(len);
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        result.reserve(10000);   
        dfs(num, target, 0, 0, 0);
        return result;
    }
};