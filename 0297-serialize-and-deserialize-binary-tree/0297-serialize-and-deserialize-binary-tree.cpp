/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(root==NULL) return s;
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* n=q.front();
            q.pop();
            if(n==NULL) s.append("#,");
            else{
                s.append(to_string(n->val)+',');
            }
            if(n!=NULL){
                q.push(n->left);
                q.push(n->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        queue<TreeNode*>q;
        stringstream s(data);
        string str;
        
        getline(s,str,',');
        TreeNode* root= new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode* n=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#") n->left=NULL;
            else{
                TreeNode* leftt=new TreeNode(stoi(str));
                n->left=leftt;
                q.push(leftt);
            }
            getline(s,str,',');
            if(str=="#") n->right=NULL;
            else{
                TreeNode* rightt=new TreeNode(stoi(str));
                n->right=rightt;
                q.push(rightt);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));