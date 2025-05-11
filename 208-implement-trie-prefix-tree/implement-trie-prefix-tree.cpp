class Trie {
    private: 
        struct TreeNode{
            char letter;
            vector<TreeNode*> children;
            bool isEnd;
            TreeNode(char c):letter(c),isEnd(false){}
        };

        void continiousDown(const string& word,int index,TreeNode*& node){
            for(int i=index;i<word.length();++i){
                TreeNode* newNode = new TreeNode(word[i]);
                node->children.push_back(newNode);
                node=newNode;
            }
            node->isEnd=true;
        }

        void findCommon(const string& word,int& index,TreeNode*& node){
            if(index>=word.length()) return ;
            for (auto child : node->children) {
                if (child->letter == word[index]) {
                    index++;
                    node=child;
                    findCommon(word, index, node);
                    return;
                }
            }
        }

        TreeNode* root;
public:
    Trie() {
        root=new TreeNode('0'); //Dummy Node
    }
    
    void insert(string word){
        TreeNode* cur=root;
        int index=0;
        findCommon(word,index,cur);
        continiousDown(word,index,cur);
    }
    
    bool search(string word) {
        TreeNode* cur=root;
        for(char c:word){
            bool found=false;
            for(auto child:cur->children){
                if(child->letter==c){
                    cur=child;
                    found=true;
                    break;
                }
            }
            if(!found) return false;
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TreeNode* cur=root;
        for(char c:prefix){
            bool found=false;
            for(auto child:cur->children){
                if(child->letter==c){
                    cur=child;
                    found=true;
                    break;
                }
            }
            if(!found) return false;
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