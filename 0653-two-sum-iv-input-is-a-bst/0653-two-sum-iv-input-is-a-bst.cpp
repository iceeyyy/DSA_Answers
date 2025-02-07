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
    void ino(TreeNode* root,vector<int>& inOr){
        if(root==NULL) return;
        ino(root->left,inOr);
        inOr.push_back(root->val);
        ino(root->right,inOr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inOr;
        ino(root,inOr);
        int l=0;
        int r=inOr.size()-1;
        while(l<r){
            int sum=inOr[l]+inOr[r];
            if(sum==k) return true;
            if(sum>k){
                r--;
            }
            else{
                l++;
            }
        }
        return false;

    }
};