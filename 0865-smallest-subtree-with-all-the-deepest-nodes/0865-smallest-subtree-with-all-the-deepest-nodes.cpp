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
using pii = pair<int,TreeNode*>;
    pii solve(TreeNode* root){
        if(root==NULL) return {0,NULL};
        
        pii left = solve(root->left);
        pii right = solve(root->right);

        if(left.first == right.first) return {left.first+1,root};
        else if(left.first>right.first) return {left.first+1,left.second};
        else return {right.first+1,right.second};

    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).second;
    }
};