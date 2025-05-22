struct Node{
    Node* arr[2];

    bool contains(int bit){
        return arr[bit]!=NULL;
    }

    void set(int bit ,Node* node){
        arr[bit]=node;
    }

    Node* next(int bit){
        return arr[bit];
    }
};
class Trie{

    Node* root;
public:
    Trie(){
        root = new Node();
    }
public:
    void insert(int num){

        Node* node = root;

        for(int i=31;i>=0;i--){

            int bit = (num>>i) & 1;

            if(!node->contains(bit)){
                node->set(bit,new Node());
            }

            node = node->next(bit);

        }
    }
public:
    int getMax(int num){
        Node* node = root;
        int maxNum=0;

        for(int i=31;i>=0;i--){

            int bit = (num>>i) & 1;

            if(node->contains(1-bit)){
                maxNum = maxNum | (1<<i);
                node = node->next(1-bit);
            }

            else{
                node = node->next(bit);
            }
        }
        return maxNum;
    }
};

class Solution {

public:
    int findMaximumXOR(vector<int>& nums) {

        Trie trie;

        for(auto i:nums){
            trie.insert(i);
        }

        int ans = INT_MIN;

        for(auto it : nums){
            ans = max(ans,trie.getMax(it));
        }

        return ans;
    }
};