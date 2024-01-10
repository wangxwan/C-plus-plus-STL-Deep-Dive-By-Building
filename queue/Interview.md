## Common Interview Questions

Interview questions about queues often cover fundamental concepts, data structure design, algorithms, and application scenarios. Here are some frequently asked questions and their answers.

### High-Frequency Interview Questions

1. **Implement a Queue:**

   - **Problem Description:** Implement a basic queue data structure using an array or linked list.
   - **Answer Summary:** You can use a dynamic array (like `std::vector` in C++) or a linked list (like `std::list` in C++) to store the queue elements.  You need to implement basic operations such as `enqueue` (add to the rear), `dequeue` (remove from the front), `front` (view the front element), and `isEmpty` (check if the queue is empty).

2. **Implement a Queue using Stacks:**

   - **Problem Description:** How can you implement queue functionality using only stack data structures?
   - **Answer Summary:** Use two stacks. One stack is used for enqueue operations, and the other for dequeue operations. When performing a dequeue operation and the dequeue stack is empty, pop all elements from the enqueue stack one by one and push them onto the dequeue stack.  The top of the dequeue stack will then be the element that was enqueued first.

3. **Difference between Queue and Stack:**

   - **Problem Description:** Describe the differences between queue and stack data structures.
   - **Answer Summary:** A queue is a First-In, First-Out (FIFO) data structure, while a stack is a Last-In, First-Out (LIFO) data structure. In a queue, elements are added at one end (rear) and removed from the other end (front); in a stack, elements are added and removed from the same end.

4. **Implementation of a Circular Queue:**

   - **Problem Description:** How do you implement a circular queue, and what are its advantages?
   - **Answer Summary:** A circular queue can be implemented using a fixed-size array and two pointers (head and tail pointers). When the tail pointer reaches the end of the array, it wraps around to the beginning of the array. The advantage of a circular queue is that it reuses space, reducing the performance overhead associated with resizing.

5. **Difference between Blocking and Non-Blocking Queues:**

   - **Problem Description:** Explain the difference between blocking and non-blocking queues.
   - **Answer Summary:** A blocking queue blocks dequeue operations when the queue is empty and blocks enqueue operations when the queue is full. A non-blocking queue does not block threads; if an operation cannot be performed immediately, it fails or returns a specific value.

6. **Application Scenarios of Queues:**

   - **Problem Description:** Give examples of where queues are used in real-world applications.
   - **Answer Summary:** Queues are commonly used for managing various resources, such as task scheduling in operating systems, packet management in networks, print job management, etc. They are also widely used in algorithms such as Breadth-First Search (BFS).

7. **Implement a Circular Queue:**

   - **Problem Description:** Implement a circular queue.
   - **Answer Summary:**

   ```cpp
   // Circular Queue implementation using an array
   class CircularQueue {
       int *arr;
       int capacity;
       int front;
       int rear;
   
   public:
       CircularQueue(int size = 10) {
           arr = new int[size];
           capacity = size;
           front = 0;
           rear = -1;
       }
   
       ~CircularQueue() {
           delete[] arr;
       }
   
       void enqueue(int item) {
           if (isFull()) {
               std::cout << "Queue is full\n";
               return;
           }
           rear = (rear + 1) % capacity;
           arr[rear] = item;
       }
   
       int dequeue() {
           if (isEmpty()) {
               std::cout << "Queue is empty\n";
               return -1;
           }
           int item = arr[front];
           front = (front + 1) % capacity;
           return item;
       }
   
       bool isFull() {
           return (front == (rear + 1) % capacity);
       }
   
       bool isEmpty() {
           return (front == rear + 1);
       }
   };
   ```
