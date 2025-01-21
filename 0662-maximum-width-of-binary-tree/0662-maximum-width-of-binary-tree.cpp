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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
        queue<pair<TreeNode* ,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int s=q.size();
            int mm=q.front().second;
            int first,last;
            for(int i=0;i<s;i++){
                int cur_i=q.front().second-mm;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=cur_i;
                if(i==s-1) last=cur_i;
                if(node->left) q.push({node->left,(long long)cur_i*2+1});
                if(node->right) q.push({node->right,(long long)cur_i*2+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};