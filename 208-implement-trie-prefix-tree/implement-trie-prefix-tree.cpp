class Trie {
    private: 
        struct TreeNode{
            char letter;
            TreeNode* children[26];
            bool isEnd;
            TreeNode(char c):letter(c),isEnd(false){
                fill(begin(children),end(children),nullptr);
            }
        };

        TreeNode* root;
public:
    Trie() {
        root=new TreeNode('0'); //Dummy Node
    }
    
    void insert(string word){
        TreeNode* cur=root;
        for(char c:word){
            int index=c-'a';
            if(!cur->children[index]){
                cur->children[index]=new TreeNode(c);
            }
            cur=cur->children[index];
        }
        cur->isEnd=true;
    }
    
    bool search(string word) {
        TreeNode* cur=root;
        for(char c:word){
            int index=c-'a';
            if(!cur->children[index]) return false;
            cur=cur->children[index];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TreeNode* cur=root;
        for(char c:prefix){
            int index=c-'a';
            if(!cur->children[index]) return false;
            cur=cur->children[index];
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