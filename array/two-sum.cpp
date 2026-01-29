class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>hashmap;
        for(int i=0;i<nums.size();i++){
           int more = target - nums[i];
           if(hashmap.find(more)!=hashmap.end()){
            return {i,hashmap[more]};
           }
            hashmap[nums[i]]=i;
        }
        return {};
    }  
};