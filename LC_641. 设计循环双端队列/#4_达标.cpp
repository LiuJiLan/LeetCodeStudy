//2020.10.15_#4_达标

class MyCircularDeque {
private:
    vector<int> list;
    int front;
    int rear;
    int capacity;
    int count;
    
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        list = vector<int>(k);
        front = 0;
        rear = k - 1;
        capacity = k;
        count = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (count == capacity) {
            return false;
        }
        
        list[front] = value;
        front = (front + 1) % capacity;
        count++;
        
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (count == capacity) {
            return false;
        }
        
        list[rear] = value;
        rear = (rear - 1 + capacity) % capacity;
        count++;
        
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (count == 0) {
            return false;
        }
        
        front = (front - 1 + capacity) % capacity;
        count--;
        
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (count == 0) {
            return false;
        }
        
        rear = (rear + 1) % capacity;
        count--;
        
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (count == 0) {
            return -1;
        }
        
        return list[(front - 1 + capacity) % capacity];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (count == 0) {
            return -1;
        }
        
        return list[(rear + 1) % capacity];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return count == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return count == capacity;
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
