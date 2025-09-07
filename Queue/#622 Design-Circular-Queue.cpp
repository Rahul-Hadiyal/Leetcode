class MyCircularQueue {
private:
    int *queue;  // storage for the queue
    int front;      // index of the front element
    int rear;       // index of the last element
    int size;      // current number of elements
    int MAX; 
public:
    MyCircularQueue(int k) {
        MAX = k;
        queue = new int[MAX];
        size = 0;
        front = -1;
        rear = -1;  
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        if(front == -1 )
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1)%MAX;
        }
        queue[rear] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1)%MAX;
        }
        size--;
        return true;  
    }
    
    int Front() {
        if(isEmpty()) return -1;
        else return queue[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        else return queue[rear];
        
    }
    
    bool isEmpty() {
        return front==-1;
    }
    
    bool isFull() {
        return (rear+1)%MAX == front;
        
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