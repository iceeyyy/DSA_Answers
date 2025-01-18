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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;

        queue<pair<TreeNode*,pair<int,int>>> q;

        vector<vector<int>> ans;

        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* n=p.first;
            int ver=p.second.first;
            int lvl=p.second.second;
            nodes[ver][lvl].insert(n->val);
            if(n->left) q.push({n->left,{ver-1,lvl+1}});
            if(n->right) q.push({n->right,{ver+1,lvl+1}});
        }
        for(auto p:nodes){
            vector<int> c;
            for(auto s:p.second){
                c.insert(c.end(),s.second.begin(),s.second.end());
            }
            ans.push_back(c);
        }
        return ans;
    }
};