class myQueue {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
  public:
    myQueue(int n) {
        // Define Data Structures
        capacity=n;
        arr=new int[capacity];
        size=0;
        front=0;
        rear=-1;
    }

    bool isEmpty() {
        // check if the queue is empty
        return size==0;
    }

    bool isFull() {
        // check if the queue is full
        return size==capacity;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull())return;
        rear=(rear+1)%capacity;
        arr[rear]=x;
        size++;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty())return ;
        front=(front+1)%capacity;
        size--;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty())return -1;
        return arr[front];
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty())return -1;
        return arr[rear];
    }
};
