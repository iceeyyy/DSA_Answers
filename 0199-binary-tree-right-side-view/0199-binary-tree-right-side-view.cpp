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
    void helper(TreeNode* node,int lvl,vector<int>& ds){
        if(node==NULL) return;
        if(lvl==ds.size()) ds.push_back(node->val);
        helper(node->right,lvl+1,ds);
        helper(node->left,lvl+1,ds); 
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        helper(root,0,ans);
        return ans;
    }
};