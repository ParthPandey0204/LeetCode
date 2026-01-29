class Solution {
public:
    int maximum(vector<int>weights){
        int n = weights.size();
        int maxi =INT_MIN;
        for(int i =0;i<n;i++){
         maxi = max(maxi,weights[i]);
        }
        return maxi;
    }
    int sum(vector<int>weights){
        int n = weights.size();
        int sum =0;
        for(int i=0;i<n;i++){
            sum+= weights[i];
        }
        return sum;

    }
    int possible(vector<int>& weights,int capacity){
         int n = weights.size();
          int day =1;
          int load =0;
         for(int i=0;i<n;i++){
            if(weights[i]+ load>capacity){
                day += 1;
                load = weights[i];
            }
            else load += weights[i];
         }
         return day;
       
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low =  maximum(weights);
        int high =  sum(weights);
        while(low<=high){
            int mid = (low +high)/2;
            int check_date = possible(weights,mid);
            if(check_date <= days){
                high = mid -1;
            }
            else{
                low = mid +1;
            }
        }
        return low;
        
    }
};