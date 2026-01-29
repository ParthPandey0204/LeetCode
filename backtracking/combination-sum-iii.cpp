class Solution {
public:
    vector<vector<int>> ans;
    vector<int> ds;

    void solve(int start, int k, int target) {
        if (k == 0 && target == 0) {
            ans.push_back(ds);
            return;
        }
        if (k == 0 || target < 0) return;

        for (int i = start; i <= 9; i++) {
            ds.push_back(i);
            solve(i + 1, k - 1, target - i);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        solve(1, k, n);
        return ans;
    }
};
