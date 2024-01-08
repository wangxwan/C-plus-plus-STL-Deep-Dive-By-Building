# Common Interview Questions

1. **What are the characteristics of a Stack data structure?**

   **Answer:** A stack is a Last-In, First-Out (LIFO) data structure. This means the last element pushed onto the stack is the first one to be popped off.  It's analogous to a stack of plates; you can only add or remove plates from the top.

2. **Explain the two basic operations of a stack.**

   **Answer:** The two basic operations of a stack are `push` and `pop`.  `push` adds an element to the top of the stack, while `pop` removes the top element. These operations maintain the LIFO property, providing mechanisms for insertion and deletion.

3. **What is Stack Overflow?**

   **Answer:** Stack overflow occurs in two scenarios: attempting a `push` operation on a full stack or attempting a `pop` operation on an empty stack. In computer programming, it usually refers to a program exceeding the allocated stack memory, potentially causing a program crash.

4. **How can you use a stack to determine if parentheses in a string are balanced?**

   **Answer:** A stack can efficiently determine if parentheses in a string are balanced. The algorithm is as follows:

   - Iterate through each character in the string.
   - When an opening parenthesis (e.g., '(', '[', '{') is encountered, push it onto the stack.
   - When a closing parenthesis is encountered, check if the top of the stack contains the corresponding opening parenthesis:
     - If it does, pop the top element from the stack.
     - If it doesn't, or the stack is empty, the parentheses are unbalanced.
   - After iteration, if the stack is empty, the parentheses are balanced; otherwise, they are unbalanced.

5. **How can you implement a queue using two stacks?**

   **Answer:** Two stacks can be combined to implement a queue's First-In, First-Out (FIFO) property.  The method is:

   - One stack (Stack A) is used for enqueue operations (pushing elements onto Stack A).
   - The other stack (Stack B) is used for dequeue operations. When Stack B is empty and a dequeue is needed, all elements from Stack A are popped and pushed onto Stack B.  This moves the bottom element of Stack A to the top of Stack B, allowing it to be popped.  This ensures the first element enqueued is the first dequeued, achieving FIFO behavior.

6. **How can you implement a non-recursive version of a recursive function using a stack?**

   **Answer:** Any recursive function can be converted to a non-recursive form using a stack. This is because recursive functions internally use the call stack to handle function calls. To convert to a non-recursive form, manually simulate the recursive process using a stack:

   - Create a stack to store function states, including parameters and local variables.
   - Begin executing the function as usual, but instead of making a recursive call, push the necessary state onto the stack whenever the function would normally recursively call itself.
   - Each time the function would normally return, pop the top state from the stack and resume execution from that point.  Continue until the stack is empty.


7. **What is a stack and what are its operations?**

   **Answer:** A stack is a First-In, Last-Out (FILO) data structure. Its basic operations include:

   - **push**: Adds an element to the top of the stack.
   - **pop**: Removes the top element from the stack.
   - **top/peek**: Views the top element without removing it.
   - **isEmpty**: Checks if the stack is empty.
   - **size**: Gets the number of elements in the stack.

8. **How to use a stack to convert infix expression to postfix expression?**

   **Answer:** Infix to postfix (reverse Polish notation) conversion can be done using a stack:

   - Create an empty stack for operators and an output list.
   - Scan the infix expression from left to right.
   - Add operands to the output list.
   - For operators, compare with the top of the stack:
     - If the stack is empty or the top is '(', push the operator.
     - If the operator's precedence is higher, push it.
     - Otherwise, pop operators from the stack to the output list until a lower precedence operator is encountered, then push the current operator.
   - Push '(' onto the stack.
   - On ')', pop operators until '(' is encountered (discard '(').
   - After scanning, pop remaining operators to the output list.
   - The output list is the postfix expression.

9. **Describe how to use a stack to check for balanced parentheses.**

   **Answer:** To check for balanced parentheses, use a stack:

   - Create an empty stack.
   - Iterate through the string:
     - Push opening parentheses ('(', '{', '[') onto the stack.
     - For closing parentheses (')', '}', ']'), check if the stack is empty. If so, it's unbalanced. If not, pop the top and check if it matches. If not, it's unbalanced.
   - If the stack is empty after iteration, the parentheses are balanced. Otherwise, they are unbalanced.

10. **How to implement a queue using two stacks?**

   **Answer:** Use two stacks, one for enqueue (Stack A) and one for dequeue (Stack B):

   - **Enqueue:** Push onto Stack A.
   - **Dequeue:**
     - If Stack B is not empty, pop from Stack B.
     - If Stack B is empty, pop all elements from Stack A and push them onto Stack B, then pop from Stack B.  This ensures FIFO.