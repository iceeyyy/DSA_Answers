struct Node{
    Node* arr[26];
    bool fl = false;
    //checking if the character exists or not
    bool contains(char c){
        return arr[c-'a'] != NULL;
    }
    //inserting
    void get(char c,Node* node){
        //returns a new node
        arr[c-'a'] = node;
    }
    Node* next(char c){
        //returns the node that  character points to 
        return arr[c-'a'];
    }
    bool isEnd(){
        return fl;
    }
    
    void setEnd(){
        fl = true;
    }
    //sets the fl of end node to true
};

class Trie {
public:
   Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {

        Node* node = root;

        for(int i=0;i<word.length();i++){
            //if it is not present then create a new node 
            if(!node->contains(word[i])){
                node->get(word[i],new Node());
            }

           node = node->next(word[i]);

        }

        node->setEnd();
    }
    
    bool search(string word) {

        Node* node = root;
        
        for(int i=0;i<word.length();i++){

            if(!node->contains(word[i])){
                return false;
            }

           node = node->next(word[i]);

        }
       return  node->isEnd();
        //if will return true if fl is true 
    }
    
    bool startsWith(string prefix) {

        Node* node = root;

        for(int i=0;i<prefix.length();i++){

            if(!node->contains(prefix[i])){
                return false;
            }

           node = node->next(prefix[i]);

        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */