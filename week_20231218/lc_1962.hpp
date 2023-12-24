class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int, vector<int>> q(piles.begin(), piles.end());
        for(int i = 0; i < k; ++i){
            int t = q.top();
            q.pop();
            t -= floor(t/2);
            q.push(t);
        }
        int ans = 0;
        while(!q.empty()){
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};