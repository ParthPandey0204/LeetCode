class Solution {
public:
    int singleNumber(vector<int>& nums) {
       map <int,int> hashMap; 
       int n = nums.size();
       for(int i =0; i<n; i++){
          hashMap[nums[i]]++;
       }
       for(auto it : hashMap){
        if(it.second == 1){
            return it.first;
        }
       }
      return -1;
    }
};