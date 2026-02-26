class Solution {
public:
    vector<string> result;
    
    void backtrack(string& num, int target, int index, 
                   long currentValue, long prevValue, string expression) {
        
        if (index == num.length()) {
            if (currentValue == target) {
                result.push_back(expression);
            }
            return;
        }
        
        for (int i = index; i < num.length(); i++) {
            
            // Avoid numbers with leading zero
            if (i > index && num[index] == '0') break;
            
            string part = num.substr(index, i - index + 1);
            long number = stol(part);
            
            if (index == 0) {
                // First number (no operator before it)
                backtrack(num, target, i + 1, number, number, part);
            } else {
                // Addition
                backtrack(num, target, i + 1,
                          currentValue + number,
                          number,
                          expression + "+" + part);
                
                // Subtraction
                backtrack(num, target, i + 1,
                          currentValue - number,
                          -number,
                          expression + "-" + part);
                
                // Multiplication
                backtrack(num, target, i + 1,
                          currentValue - prevValue + (prevValue * number),
                          prevValue * number,
                          expression + "*" + part);
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        backtrack(num, target, 0, 0, 0, "");
        return result;
    }
};