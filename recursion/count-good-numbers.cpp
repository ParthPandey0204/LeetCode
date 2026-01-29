class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long x , long long n , long long mod ){
        long long res = 1LL;
        x = x % mod;
        while(n>0){
            if(n % 2 ==1){
                res = (res * x) % MOD;
            }
            x = (x*x) % MOD;
            n = n/2;
        }
        return res;
    }
    int countGoodNumbers(long long n){
        long long even = (n+1)/2;
        long long odd = n/2;
        long long ans = 
             (power(5,even,MOD)*power(4,odd,MOD))%MOD;
        return ans;
    }

};