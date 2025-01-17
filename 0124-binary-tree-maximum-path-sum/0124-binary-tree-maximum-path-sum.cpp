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
    int helper(TreeNode* node,int &maxi){
        if(node==NULL) return 0;

        int lh=max(0,helper(node->left,maxi)); // for ignoring negative path sums
        int rh=max(0,helper(node->right,maxi));
        maxi=max(maxi , lh + rh + node->val);

        return max(lh,rh) + node->val;
    }
    int maxPathSum(TreeNode* root) {
        int path=INT_MIN;
        helper(root,path);
        return path;
    }
};