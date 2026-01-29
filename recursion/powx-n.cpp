class Solution {
public:
   double myPow(double x, int n) {
    long long N = n;
    bool is_negative = false;
    if(N <0){
        is_negative = true;
        N = -N;
    }
    double result = 1.0;
    while(N>0){
        if(N % 2 == 1){
            result = result *x;  
        }
        x = x * x;
        N = N/2;
    }
    if (is_negative){
        result = 1.0/result;
    }
    return result;
}
};