class MyCircularQueue {
public:
    vector<int>arr;
    int n;
    int i=-1,j=-1;
    MyCircularQueue(int k) {
        n=k;
        arr.resize(n);
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        i=(i+1)%n;
        arr[i]=value;
        if(j==-1) j=0;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(j==i){
            i=-1;
            j=-1;
        } else j=(j+1)%n;
        return true;
    }
    
    int Front() {
        if(j!=-1) return arr[j];
        return -1;
    }
    
    int Rear() {
        if(i!=-1) return arr[i];
        return -1;
    }
    
    bool isEmpty() {
        if(i==-1) return true;
        return false;
    }
    
    bool isFull() {
        if(isEmpty()) return false;
        return ((i+1)%n==j);
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