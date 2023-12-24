class Solution {
public:
    void calc_lr(vector<int>& maxHeights, vector<long long>& dp, int n) {
        stack<int> st;
        for(int i = 0; i < n; ++i){
            while(!st.empty() && maxHeights[i] < maxHeights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                dp[i] = 1LL * (i+1) * maxHeights[i];
            }else{
                dp[i] = dp[st.top()] + 1LL * (i-st.top()) * maxHeights[i];
            }
            st.push(i);
        } 
    }

    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long> L(n), R(n);
        calc_lr(maxHeights, L, n);
        reverse(maxHeights.begin(), maxHeights.end());
        calc_lr(maxHeights, R, n);
        long long ans = 0;
        for(int i = 0; i < n; ++i){
            ans = max(ans, R[i] + L[n-i-1] - maxHeights[i]);
        }
        return ans;
    }
};