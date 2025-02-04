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
    void dfs(TreeNode* node,int k,TreeNode*&ans,int& cnt){
        if(node==NULL) return;
         
        dfs(node->left,k,ans,cnt);

        cnt++;
        if(cnt==k){
            ans=node;
            return;
        }
        
        dfs(node->right,k,ans,cnt);
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* ans=NULL;
        int cnt=0;
        dfs(root,k,ans,cnt);
        return (ans->val);
    }
};