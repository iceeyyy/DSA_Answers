/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mp){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* n=q.front();
            q.pop();
            if(n->left){
                q.push(n->left);
                mp[n->left]=n;
            }
            if(n->right){
                q.push(n->right);
                mp[n->right]=n;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        queue<TreeNode*>q;

        parent(root,mp);

        unordered_map<TreeNode*,bool> visited;
        q.push(target);
        visited[target]=1;
        int dis=0;
        while(!q.empty()){
            int s=q.size();
            if(dis++==k) break;
            for(int i=0;i<s;i++){
                TreeNode* cur=q.front();
                q.pop();
                if(cur->left && !visited[cur->left]){
                    q.push(cur->left);
                    visited[cur->left]=1;
                }
                if(cur->right && !visited[cur->right]){
                    q.push(cur->right);
                    visited[cur->right]=1;
                }
                if(mp[cur] && !visited[mp[cur]]){
                    q.push(mp[cur]);
                    visited[mp[cur]]=1;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* v=q.front();
            q.pop();
            ans.push_back(v->val);
        }
        return ans;
    }
};