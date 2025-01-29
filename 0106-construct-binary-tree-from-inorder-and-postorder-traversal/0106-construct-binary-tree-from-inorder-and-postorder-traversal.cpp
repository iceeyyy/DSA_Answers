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
    TreeNode* build(vector<int>& inorder,int inS,int inE,vector<int>& postorder,int pS,int pE, unordered_map<int,int>& mpp){
        if(inS>inE|| pS>pE){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[pE]);

        int inroot= mpp[root->val];
        int left=inroot-inS;

        root->left=build(inorder,inS,inroot-1,postorder,pS,pS+left-1,mpp);
        root->right=build(inorder,inroot+1,inE,postorder,pS+left,pE-1,mpp);

        return root;


    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root=build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
        return root;
    }
};