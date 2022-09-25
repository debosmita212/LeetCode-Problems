class MyCircularQueue {
private:
    vector<int> v;
    int start=0,len=0;
public:
    MyCircularQueue(int k) : v(k){
        //initialize k size of array
        
    }
    
    bool enQueue(int value) {
        //if full then cannot insert anymore
        if(isFull()) return false;
        //circular queue use modular concept
        v[(start+len)%v.size()]=value;
        //increase the length
        len++;
        return true;
    }
    
    bool deQueue() {
        //if empty cannot delete anymore
        if(isEmpty()) return false;
        //increase start and decrease length
        start=(start+1)%v.size();
        --len;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return v[start];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        //for rear use modular concept again
        return v[(start+len-1)%v.size()];
    }
    
    bool isEmpty() {
        return len==0;
    }
    
    bool isFull() {
        return len==v.size();
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