class Solution {
public:
    const int mod = 1e9+7;

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        vector<long long> dp(n);
        for(int i = 0; i < arr.size(); ++i){
            while(!stk.empty() && arr[i] <= arr[stk.top()]){
                stk.pop();
            }
            long long tmp = 0;
            if(stk.empty()){
                tmp = arr[i]*(i+1)%mod;
                dp[i] = tmp;
            }else{
                tmp = arr[i]*(i-stk.top())%mod;
                dp[i] = (tmp + dp[stk.top()])%mod;
            }
            stk.push(i);
        }
        long long ans = 0;
        for(auto val : dp){
            ans = (ans+val)%mod;
        }
        return ans;
    }
};