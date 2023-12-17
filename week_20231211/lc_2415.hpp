/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int height = 0;
        while(!q.empty()){
            vector<TreeNode*> tmp;
            height++;
            while(!q.empty()){
                TreeNode* t = q.front();
                q.pop();
                if(t->left) tmp.emplace_back(t->left);
                if(t->right) tmp.emplace_back(t->right);
            }
            if(height%2 != 0){
                int n = tmp.size();
                for(int i = 0; i < n/2; ++i){
                    swap(tmp[i]->val, tmp[n-i-1]->val); 
                }
            }
            for(int i = 0; i < tmp.size(); ++i){
                q.push(tmp[i]);
            }
        }
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        bfs(root);
        return root;
    }
};