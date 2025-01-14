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
    void preo(TreeNode* node,vector<int>&ds){
        if(node==NULL) return;
        ds.push_back(node->val);
        preo(node->left,ds);
        preo(node->right,ds);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preo(root,ans);
        return ans;
    }
};