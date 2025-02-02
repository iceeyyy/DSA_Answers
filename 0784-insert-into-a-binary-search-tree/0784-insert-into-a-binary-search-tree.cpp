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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        TreeNode* n=root;
        TreeNode* parent=NULL;
        while(n){
            parent=n;
            if(n->val < val){
                n=n->right;
            }
            else{
                n=n->left;
            }
        }
        if(parent->val>val){
            parent->left=new TreeNode(val);
        }
        if(parent->val<val){
            parent->right=new TreeNode(val);
        }
        return root;
    }
};