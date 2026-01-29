class Solution {
public:
    int maximum(vector<int>& nums){
        int n = nums.size();
        int maxi =0;
        for(int i =0;i<n;i++){
           maxi = max(maxi,nums[i]);
        }
        return maxi;
    }
     int possible(vector<int>& nums,int floater){
        int n = nums.size();
        int sum =0;
        for(int i =0;i<n;i++){
            sum+=ceil((double)nums[i]/(double)floater);
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low =1;
        int high = maximum(nums);
        while(low<=high){
            int mid = (low+high)/2;
            int sum =possible(nums,mid);
            if(sum<=threshold){
                high = mid -1;
            }
            else{
                low = mid +1;
            }
        }
        return low;
        
    }
};