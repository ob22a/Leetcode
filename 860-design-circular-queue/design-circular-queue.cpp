class MyCircularQueue {
public:
    vector<int> circularQueue;
    int maxSize,front=-1,rear=-1;
    MyCircularQueue(int k) {
        maxSize=k;
        circularQueue.resize(k);
    }
    
    bool enQueue(int value) {
        int temp=(rear+1)%maxSize;
        if(temp==front) return false;
        if(isEmpty()) front=0;

        rear=temp;
        circularQueue[rear]=value;
        return true;
    }
    
    bool deQueue() {
        if(!isEmpty()){
            if(front==rear){
                front=rear=-1;
            }
            else front=(front+1)%maxSize;
            return true;
        }
        return false;
    }
    
    int Front() {
        return isEmpty()?-1:circularQueue[front];
    }
    
    int Rear() {
        return isEmpty()?-1:circularQueue[rear];
    }
    
    bool isEmpty() {
        return front==-1;
    }
    
    bool isFull() {
        return (rear+1)%maxSize==front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */