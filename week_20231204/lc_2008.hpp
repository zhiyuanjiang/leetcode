class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<long long> dp(n+1);
        vector<vector<int>> rec(n+1);
        for(int i = 0; i < rides.size(); ++i){
            rec[rides[i][1]].emplace_back(i);
        } 
        for(int i = 1; i <= n; ++i){
            dp[i] = dp[i-1];
            for(auto& pos : rec[i]){
                auto& tmp = rides[pos];
                dp[i] = max(dp[i], dp[tmp[0]] + tmp[1]-tmp[0]+tmp[2]);
            }
        }
        return dp[n];
    }
};