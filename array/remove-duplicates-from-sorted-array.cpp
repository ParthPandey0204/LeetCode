class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>laudalasan;
        int n =nums.size() ;
        for(int i = 0; i < nums.size() ; i++){
        laudalasan.insert(nums[i]);
        }
        int k = laudalasan.size();
        int index = 0;
        for(auto it: laudalasan){
            nums[index] = it;
            index ++;
            
           
        }
         return k;
    }
};