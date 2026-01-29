
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0 || nums.size() == 0) return; 

        int d = k;
        vector<int> temp(d);
        for (int i = 0; i < d; i++) {
            temp[i] = nums[nums.size() - d + i];
        }
        for (int i = nums.size() - d - 1; i >= 0; i--) {
            nums[i + d] = nums[i];
        }      
        for (int i = 0; i < d; i++) {
            nums[i] = temp[i];
        }
    }
};