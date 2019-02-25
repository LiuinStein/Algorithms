static int ____ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class MyCircularQueue {
    int *a;
    int front, rear, size, capacity;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : a(new int[k]), front(0), rear(-1), size(0), capacity(k)
    {
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull())
        {
            return false;
        }
        ++size;
        a[rear = (rear + 1) % capacity] = value;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty())
        {
            return false;
        }
        --size;
        front = (front + 1) % capacity;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        return isEmpty() ? -1 : a[front];
    }

    /** Get the last item from the queue. */
    int Rear() {
        return isEmpty() ? -1 : a[rear];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == capacity;
    }
};
