class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0 ; int high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] == nums[low] && nums[high] == nums[mid]){
                high = high -1;
                low = low +1;
                continue;
            }
            if(nums[mid] <= nums[high]){
                if(nums[mid] < target && target <= nums[high]){
                    low = mid+1;
                }
                else 
                high = mid-1;
            }
               if(nums[mid] >= nums[low]){
                if(nums[mid] > target && target >= nums[low]){
                 high = mid-1;
                }
                else 
                low = mid+1;
            }
        }
        return -1;
    }
};