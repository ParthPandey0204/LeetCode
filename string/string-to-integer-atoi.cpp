class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0)return 0;
       int i=0;
       while(i<s.size() && s[i]==' '){
            i++;
       }
        s=s.substr(i);
        int sign =1;
        long long num = 0;
        if(s[0]=='-')sign = -1; 
        if(s[0]=='+'||s[0]=='-'){
            i=1;
        }
        else {
            i=0;
            }

        while(i<s.size()){
            if(s[0]==' ' || !isdigit(s[i]))break;
            num = num*10 + (s[i]-'0');
            if(sign == -1 && -1*num < INT_MIN)return INT_MIN;
            if(sign == 1 && 1*num > INT_MAX)return INT_MAX;
            i++;
        }
        return sign*num;
    }
};