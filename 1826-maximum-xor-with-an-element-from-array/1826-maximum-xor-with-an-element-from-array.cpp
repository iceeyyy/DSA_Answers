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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        //sort the nums array in a ascending order
        vector<pair<int,pair<int,int>>> oq;
        //for sorting queires in a ascending order by implementing by ai
        int q = queries.size();
        int n = nums.size();

        vector<int> ans(q,0);

        for(int i=0;i<q;i++){
            //for sorting queries on the basis of mi
            oq.push_back({queries[i][1],{queries[i][0],i}});

        }

        sort(oq.begin(),oq.end());

        Trie* trie = new Trie() ;

        int ind=0;

        for(int i= 0;i<q; i++){

           int ai = oq[i].first;
           int xi = oq[i].second.first;
           int qind = oq[i].second.second;

            while(ind<n && nums[ind] <= ai){
                //inserting values that are less than equal to ai
                trie->insert(nums[ind]);
                ind++;
            }
            if(ind==0) ans[qind]=-1;
            else{
                ans[qind] = trie->getMax(xi);
            }
        }

        return ans;
    }
};