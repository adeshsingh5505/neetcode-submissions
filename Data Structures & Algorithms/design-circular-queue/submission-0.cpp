class MyCircularQueue {
    queue<int> q;
    int capacity;
public:
    MyCircularQueue(int k) {
        capacity=k;
    }
    
    bool enQueue(int value) {
        if(q.size()==capacity) return 0;
        q.push(value);
        return 1;
    }
    
    bool deQueue() {
        if(q.empty()) return 0;
        q.pop();
        return 1;
    }
    
    int Front() {
        if(q.empty()) return -1;
        return q.front();
    }
    
    int Rear() {
        if(q.empty()) return -1;
        return q.back();
    }
    
    bool isEmpty() {
        return q.empty();
    }
    
    bool isFull() {
        return q.size()==capacity;
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