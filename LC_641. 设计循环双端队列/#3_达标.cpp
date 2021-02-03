//2020.09.21_#3_达标

//注意命名
/*
 int front;
     int rear;
     int capacity;
 */

class MyCircularDeque {
private:
    vector<int> list;
    int size;
    int count;
    int head;
    int tail;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        list = vector<int>(k, 0);
        size = k;
        count = 0;
        head = 0;
        tail = k - 1;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (count == size) {
            return false;
        }
        
        list[head] = value;
        head = (head + 1) % size;
        count++;
        
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (count == size) {
            return false;
        }
        
        list[tail] = value;
        tail = (tail - 1 + size) % size;
        count++;
        
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (count == 0) {
            return false;
        }
        
        head = (head - 1 + size) % size;
        count--;
        
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (count == 0) {
            return false;
        }
        
        tail = (tail + 1) % size;
        count--;
        
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (count == 0) {
            return -1;
        }
        
        return list[(head - 1 + size) % size];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (count == 0) {
            return -1;
        }
        
        return list[(tail + 1) % size];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return count == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return count == size;
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
