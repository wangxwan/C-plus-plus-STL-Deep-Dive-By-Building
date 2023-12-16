# Red-Black Tree Workflow

Let's describe the insertion process:

1. **Insert New Node:** Insert the new node into the red-black tree as you would in a regular binary search tree. Initialize the new node's color to red.

2. **Check Red-Black Tree Properties:**

   1. If the newly inserted node is the root, simply change its color to black to satisfy all properties.
   2. If the parent of the new node is black, no red-black tree properties are violated, and no further action is needed.
   3. If the parent of the new node is red, adjustments are needed to repair the tree's properties because this violates the property: A red node's children must be black.

3. **Adjust Red-Black Tree:** If the parent of the new node is red, several cases need handling:

   1. The parent node is the left child of the grandparent node.
      1. The uncle node is red.
         1. Change the uncle and parent nodes to black.
         2. Set the grandparent node to red.
         3. Continue checking if adjustments are needed using the grandparent node.
      2. The uncle node is black or doesn't exist.
         1. If the new node is the right child of the parent node, change the target node to its parent and perform a left rotation.
         2. Set the target node (which might have changed due to the previous left rotation) to black and the grandparent node to red.
         3. Perform a right rotation on the grandparent node.
   2. The parent node is the right child of the grandparent node.
      1. The uncle node is red.
         1. Change the uncle and parent nodes to black.
         2. Set the grandparent node to red.
         3. Continue checking if adjustments are needed using the grandparent node.
      2. The uncle node is black or doesn't exist.
         1. If the new node is the left child of the parent node, change the target node to its parent and perform a right rotation.
         2. Set the target node (which might have changed due to the previous right rotation) to black and the grandparent node to red.
         3. Perform a left rotation on the grandparent node.

   Adjustments need to be recursively performed upwards until the root node is reached or until no red-black tree properties are violated.

Rotation operations explained:

- **Left Rotation:** Node x's right child y becomes x's parent, and x becomes y's left child. If y has a left child, it becomes x's right child.
- **Right Rotation:** The opposite of a left rotation; node x's left child y becomes x's parent, and x becomes y's right child. If y has a right child, it becomes x's left child.

The key to insertion lies in the recoloring and rotation operations, which maintain the red-black tree's balance without destroying the binary search tree properties.  While these operations seem complex, the time complexity of each insertion remains O(log n) because the height of the red-black tree stays within log₂(n).