static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class MyCircularDeque {
    int *a;
    int front, rear, size, capacity;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) : a(new int[k]), front(0), rear(-1), size(0), capacity(k) {

    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull())
        {
            return false;
        }
        ++size;
        if (front - 1 < 0)
        {
            a[front = capacity - 1] = value;
        }
        else
        {
            a[--front] = value;
        }
        rear = (front + size - 1) % capacity;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull())
        {
            return false;
        }
        ++size;
        a[rear = (rear + 1) % capacity] = value;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty())
        {
            return false;
        }
        --size;
        front = (front + 1) % capacity;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty())
        {
            return false;
        }
        --size;
        if (rear - 1 < 0)
        {
            rear = capacity - 1;
        }
        else
        {
            --rear;
        }
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        return isEmpty() ? -1 : a[front];
    }

    /** Get the last item from the deque. */
    int getRear() {
        return isEmpty() ? -1 : a[rear];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == capacity;
    }
};