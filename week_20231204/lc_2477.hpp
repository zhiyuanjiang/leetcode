class Solution {
public:
    vector<int> dp;

    int dfs(vector<vector<int>>& graph, int pre, int root, int seats) {
        int ans = 0;
        for(auto& u : graph[root]){
            if(u == pre) continue;
            int tmp = dfs(graph, root, u, seats);
            if(tmp){
                dp[root] += ceil(1.0*tmp/seats);
            }
            ans += tmp;
        }
        return ans+1;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1;
        vector<vector<int>> graph(n, vector<int>());
        for(auto& tmp : roads){
            int a = tmp[0], b = tmp[1];
            graph[a].emplace_back(b);
            graph[b].emplace_back(a);
        }
        dp = vector<int>(n, 0);
        long long ans = 0;
        dfs(graph, -1, 0, seats);
        for(auto& val : dp){
            ans += val;
        }
        return ans;
    }
};