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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int cnt=1;
        while(!q.empty()){
            TreeNode* n=q.front();
            q.pop();
            if(n->left){
                q.push(n->left);
                cnt++;
            }
            if(n->right){
                q.push(n->right);
                cnt++;
            }
        }
        return cnt;
    }
};