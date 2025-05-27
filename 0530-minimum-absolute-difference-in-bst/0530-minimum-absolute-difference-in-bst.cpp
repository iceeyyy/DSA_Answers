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
    void ino(TreeNode* root,vector<int>& ir){
        if(root==NULL) return;

        ino(root->left,ir);
        ir.push_back(root->val);
        ino(root->right,ir);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> ir;
        ino(root,ir);
        
        int ans=INT_MAX;

        for(int i=0;i<ir.size();i++){
            for(int j=i+1;j<ir.size();j++){
                int diff = abs(ir[i]-ir[j]);
                ans=min(ans,diff);
            }
        }
        

        return ans;

    }
};