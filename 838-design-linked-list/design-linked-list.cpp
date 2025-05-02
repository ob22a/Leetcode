class MyLinkedList {
    struct ListNode{
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int val):val(val),next(nullptr),prev(nullptr){};
    };
public:
    int size;
    ListNode* head;
    ListNode* tail;
    MyLinkedList() {
        head=nullptr;
        tail=nullptr;
        size=0;
    }
    
    int get(int index) {
        if(index>=size) return -1;

        else if(index<size/2){
            ListNode* cur=head;
            for(int i=0;i<index;++i){
                cur=cur->next;
            }
            return cur->val;
        }
        ListNode* cur=tail;
        for(int i=0;i<size-index-1;++i){
            cur=cur->prev;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        if(!head){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
        ++size;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if(!tail){
            tail=head=newNode;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
        ++size;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size) return;

        if(index==0){
            addAtHead(val);
            return;
        }

        else if(index==size){
            addAtTail(val);
            return;
        }

        ListNode* newNode = new ListNode(val);
        if(index<size/2){
            ListNode* cur = head;
            for(int i=0;i<index-1;++i){
                cur=cur->next;
            }
            ListNode* nextNode = cur->next;
            cur->next=newNode;
            newNode->prev=cur;
            newNode->next=nextNode;
            nextNode->prev=newNode;
        }

        else if(index>=size/2){
            ListNode* cur = tail;
            for(int i=0;i<size-index-1;++i){
                cur=cur->prev;
            }
            ListNode* prevNode=cur->prev;
            cur->prev=newNode;
            newNode->next=cur;
            newNode->prev=prevNode;
            prevNode->next=newNode;
        }
        ++size;
    }
    
    void deleteAtIndex(int index) {
        if(index>=size) return;
        
        if(size==1){
            delete head;
            head=tail=nullptr;
            size=0;
            return;
        }

        if(index==0){
            ListNode* temp = head;
            head=head->next;
            head->prev=nullptr;
            delete temp;
        }

        else if(index==size-1){
            ListNode* temp=tail;
            tail=tail->prev;
            tail->next=nullptr;
            delete temp;
        }

        else if(index<size/2){
            ListNode* cur=head;
            for(int i=1;i<index;++i){
                cur=cur->next;
            }
            ListNode* temp=cur->next;
            cur->next=cur->next->next;
            cur->next->prev=cur;
            delete temp;
        }
        else{
            ListNode* cur=tail;
            for(int i=1;i<size-index-1;++i){
                cur=cur->prev;
            }
            ListNode* temp = cur->prev;
            cur->prev=cur->prev->prev;
            cur->prev->next=cur;
            delete temp;
        }
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */