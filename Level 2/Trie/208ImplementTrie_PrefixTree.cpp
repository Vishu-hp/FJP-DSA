// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
    class Node{
        public:
        vector<Node*>children;
        bool isEnd;
        
        Node(){
            this->isEnd = false;
            children.resize(26);
            for(int i=0;i<26;++i){
                this->children[i] = NULL;
            }
        }
    };
public:
    Node* root;
    Trie() {
        this->root = new Node(); 
    }
    
    void insert(string word) {
        Node* curr=root;
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            if(curr->children[ch-'a'] == NULL){
                curr->children[ch-'a'] = new Node();
            }
            curr = curr->children[ch-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node* curr=root;
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            if(curr->children[ch-'a'] == NULL){
                return false;
            }
            curr = curr->children[ch-'a'];
        }
        if(curr->isEnd == true){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
         Node* curr=root;
        for(int i=0;i<prefix.length();i++){
            char ch = prefix[i];
            if(curr->children[ch-'a'] == NULL){
                return false;
            }
            curr = curr->children[ch-'a'];
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
