/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;

        Node* dummy=new Node(0);
        Node* cur=dummy;
        stack<Node*> stk;
        stk.push(head);
        while(!stk.empty()){
            Node* nd=stk.top(); stk.pop();
            nd->prev=cur;
            cur->next=nd;
            if(nd->next) stk.push(nd->next);
            if(nd->child){
                stk.push(nd->child);
                nd->child=nullptr;
            }
            cur=cur->next;
        }
        cur=dummy->next;
        cur->prev=nullptr;
        return cur;
    }
};