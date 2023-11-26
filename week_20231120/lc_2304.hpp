class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 0; i < n; ++i){
            ans[0][i] = grid[0][i];
        }
        for(int i = 1; i < m; ++i){
            for(int j = 0; j < n; ++j){
                ans[i][j] = 0xffffff;
                for(int k = 0; k < n; ++k){
                    ans[i][j] = min(ans[i][j], 
                        grid[i][j] + moveCost[grid[i-1][k]][j] + ans[i-1][k]);
                }
            }
        }
        int val = 0xffffff;
        for(int i = 0; i < n; ++i){
            val = min(val, ans[m-1][i]);
        }
        return val;
    }
};