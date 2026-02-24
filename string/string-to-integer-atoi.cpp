class Solution {
public:
    int myAtoi(string s) {
        int i = 0 ; 
        int n = s.length();
        while(i < n && s[i]==' ') i++;
        int sign = 1;
        if( i < n && (s[i] == '+' || s[i]== '-')){
            if(s[i] == '-')sign = -1;
            i++;
        }
        long result = solve(s , i , 0 , sign);
        return (int)(sign * result);
    }
    long solve(string &s, int i , long result , int sign){
        if( i >= s.length() || !isdigit(s[i]))
        return result;

        int digit = s[i] - '0';
         if (result > (INT_MAX - digit) / 10)
            return sign == 1 ? INT_MAX : -(long)INT_MIN;
        
        result = result * 10 + digit;
        
        return solve(s, i + 1, result, sign);
    }
};