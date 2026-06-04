class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxi = 0;

        for(int i = 0; i <= n; i++) {

            while(!st.empty() &&
                  (i == n || heights[st.top()] >= heights[i])) {

                int height = heights[st.top()];
                st.pop();

                int nse = i;

                int pse = st.empty() ? -1 : st.top();

                int width = nse - pse - 1;

                maxi = max(maxi, height * width);
            }

            st.push(i);
        }

        return maxi;
    }
};