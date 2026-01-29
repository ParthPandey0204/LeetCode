class Solution {
public:
   int maxi = 0;
   int mini = 0;
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxPro=0;
        int n = prices.size();
        for(int i = 0; i<n ; i++){
           minPrice = min(minPrice , prices[i]);
           maxPro = max(maxPro,prices[i]-minPrice);
        }
        return maxPro;
    

    }
};