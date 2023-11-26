class Solution {
public:
    vector<int> recd;

    bool judge(const vector<int>& recd) {
        int odd = 0, even = 0;
        for(int i = 0; i < recd.size(); ++i){
            if(recd[i]%2 == 0){
                even++;
            }else{
                odd++;
            }
        }
        if(odd == 0){
            return true;
        }
        if(odd == 1){
            return true;
        }
        return false;
    }

    int dfs(TreeNode* root, vector<int>& recd) {
        int ans = 0;
        recd[root->val]++;
        if(root->left){
            ans += dfs(root->left, recd);
        }
        if(root->right){
            ans += dfs(root->right, recd);
        }
        if(!root->left && !root->right){
            if(judge(recd)){
                ans++;
            }
        }
        recd[root->val]--;
        return ans;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        recd = vector<int>(10, 0);
        return dfs(root, recd);
    }
};