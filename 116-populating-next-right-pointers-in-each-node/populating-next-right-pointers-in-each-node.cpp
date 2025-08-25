/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        //bfs traversal
        queue<Node*> q;
        if(root) q.push(root);

        while(!q.empty()){
            int levelSize=q.size();
            for(int i=0;i<levelSize;++i){
                Node* node=q.front(); q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(i+1<levelSize) node->next=q.front();
                else node->next=nullptr;
            }
        }

        return root;
    }
};