class MyCircularDeque {
public:
    vector<int>arr;
    int size,curr=0;
    int front,rear;
    MyCircularDeque(int k) {
        size=k;
        arr.resize(k);
        front=0;
        rear=k-1;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        front=(front-1+size)%size;
        arr[front]=value;
        curr++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        rear=(rear+1)%size;
        arr[rear]=value;
        curr++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        arr[front]=0;
        front=(front+1)%size;
        curr--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        arr[rear]=0;
        rear=(rear-1+size)%size;
        curr--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return  (curr==0); 
    }
    
    bool isFull() {
        return curr==size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */