# Code Implementation

[Here's a basic implementation of a red-black tree.](Implementation.cpp)

#### 1. Structure Description

```cpp
struct Node {
  Key key;
  Color color;
  Node *left;
  Node *right;
  Node *parent;

  // Constructor
  Node(const Key &k, Color c, Node *p = nullptr)
      : key(k), color(c), left(nullptr), right(nullptr), parent(p) {}
};
```

Each structure needs to record its own color, key value, pointers to the left child, right child, and parent node. The constructor of this structure allocates the parent node pointer, while the other pointers are null pointers.


#### 2. `insertNode` Function

```cpp
  void insertNode(const Key &key) {
    // Create a new node, and initialize the node's color to red
    Node *newNode = new Node(key, Color::RED);
    Node *parent = nullptr; // Parent pointer of the new node
    Node *cmpNode = root;   // Node used for comparison, initially the root node

    // Traverse the tree to find the correct position for the new node
    while (cmpNode) {
      parent = cmpNode; // Keep the current node as the potential parent node of the new node
      // If the key of the new node is less than the key of the current comparison node, move to the left subtree
      if (newNode->key < cmpNode->key) {
        cmpNode = cmpNode->left;
        // If the key of the new node is greater than the key of the current comparison node, move to the right subtree
      } else if (newNode->key > cmpNode->key) {
        cmpNode = cmpNode->right;
        // If the keys are equal, it means that there is already a node with the same key in the tree, delete the new node and return
      } else {
        delete newNode;
        return;
      }
    }

    // Tree size increases
    size++;

    // Set the parent node of the new node to the found parent node position
    newNode->parent = parent;
    // If the parent node is empty, it means the tree is empty, and the new node becomes the root node
    if (!parent) {
      root = newNode;
      // If the key of the new node is less than the key of the parent node, insert the new node into the left subtree of the parent node
    } else if (newNode->key < parent->key) {
      parent->left = newNode;
      // Otherwise, insert the new node into the right subtree of the parent node
    } else {
      parent->right = newNode;
    }

    // After inserting the new node, call the insertFixup function to fix the red-black tree properties that may have been broken
    insertFixup(newNode);
  }
```

The node insertion function takes a key value as a parameter and inserts a new node into the tree. It involves finding the appropriate insertion location and performing insertion fixup operations. Finding the appropriate insertion location uses the regular binary tree search algorithm. If a duplicate key exists, the insertion is aborted; otherwise, the node is inserted, and `insertFixup` is called to repair the red-black tree properties.


#### 3. `insertFixup` Function

```cpp
  void insertFixup(Node *target) {
    // When the parent node of the target node exists and its color is red, it needs to be fixed
    while (target->parent && target->parent->color == Color::RED) {
      // When the parent node of the target node is the left child of the grandparent node
      if (target->parent == target->parent->parent->left) {
        Node *uncle = target->parent->parent->right; // Uncle node
        // If the uncle node exists and is red, perform color adjustment
        if (uncle && uncle->color == Color::RED) {
          target->parent->color = Color::BLACK; // Set parent node to black
          uncle->color = Color::BLACK;          // Set uncle node to black
          target->parent->parent->color = Color::RED; // Set grandparent node to red
          target = target->parent->parent; // Set the grandparent node as the next target node
        } else {
          // If the target node is the right child of the parent node, perform a left rotation
          if (target == target->parent->right) {
            target = target->parent; // Update the target node to the parent node
            leftRotate(target);      // Perform a left rotation on the target node
          }
          // Adjust the colors of the parent and grandparent nodes, and perform a right rotation
          target->parent->color = Color::BLACK;
          target->parent->parent->color = Color::RED;
          rightRotate(target->parent->parent);
        }
      } else {
        // When the parent node of the target node is the right child of the grandparent node, it's symmetrical to the above
        Node *uncle = target->parent->parent->left; // Uncle node
        if (uncle && uncle->color == Color::RED) {
          target->parent->color = Color::BLACK;
          uncle->color = Color::BLACK;
          target->parent->parent->color = Color::RED;
          target = target->parent->parent;
        } else {
          if (target == target->parent->left) {
            target = target->parent; // Update the target node to the parent node
            rightRotate(target);     // Perform a right rotation on the target node
          }
          // Adjust the colors of the parent and grandparent nodes, and perform a left rotation
          target->parent->color = Color::BLACK;
          target->parent->parent->color = Color::RED;
          leftRotate(target->parent->parent);
        }
      }
    }
    // Ensure that the root node is always black
    root->color = Color::BLACK;
  }
```

The insertion fixup function is used to repair situations that may violate red-black tree properties after inserting a new node. This function performs color adjustments and rotations based on red-black tree properties to ensure the tree's balance.  Fixup is only needed when the parent of the newly inserted node is red. The logic is as follows:

1. Parent is the left child of the grandparent:
   1. Uncle is red:
      1. Change uncle and parent to black.
      2. Set grandparent to red.
      3. Continue checking if adjustments are needed using the grandparent node.
   2. Uncle is black or doesn't exist:
      1. If the new node is the right child of the parent, change the target node to its parent and perform a left rotation.
      2. Set the target node (which might have changed due to the previous left rotation) to black, the grandparent node to red.
      3. Perform a right rotation on the grandparent node.
2. Parent is the right child of the grandparent:
   1. Uncle is red:
      1. Change uncle and parent to black.
      2. Set grandparent to red.
      3. Continue checking if adjustments are needed using the grandparent node.
   2. Uncle is black or doesn't exist:
      1. If the new node is the left child of the parent, change the target node to its parent and perform a right rotation.
      2. Set the target node (which might have changed due to the previous right rotation) to black, the grandparent node to red.
      3. Perform a left rotation on the grandparent node.


#### 4. `leftRotate` Function

```cpp
void leftRotate(Node *node) {
    Node *r_son = node->right;

    node->right = r_son->left;

    if (r_son->left) {
        r_son->left->parent = node;
    }

    r_son->parent = node->parent;
    if (!node->parent) {
        root = r_son;
    } else if (node == node->parent->left) {
        node->parent->left = r_son;
    } else {
        node->parent->right = r_son;
    }

    r_son->left = node;
    node->parent = r_son;
}
```

The left rotation function takes a node pointer as an argument and performs a left rotation on that node. Left rotation is a fundamental operation in red-black tree adjustments, used to maintain the balance of the tree. A left rotation promotes the right child to become the parent of the current node, and the current node becomes the left child of the new parent.  The connections with the grandparent and the original right child need to be coordinated:

1. The left subtree of the right child is given to the parent as its right subtree.
2. The right child becomes the new parent, and the connection between the right child and the grandparent needs to be handled.  (This is easier to understand with a diagram.)


#### 5. `rightRotate` Function

```cpp
void rightRotate(Node *node) {
    Node *l_son = node->left;
    node->left = l_son->right;
    if (l_son->right) {
        l_son->right->parent = node;
    }
    l_son->parent = node->parent;
    if (!node->parent) {
        root = l_son;
    } else if (node == node->parent->left) {
        node->parent->left = l_son;
    } else {
        node->parent->right = l_son;
    }
    l_son->right = node;
    node->parent = l_son;
}
```

The right rotation function is similar to left rotation but in the opposite direction. This is also one of the basic operations to maintain the balance of the red-black tree. It takes a node pointer as an argument and performs a right rotation on that node. Right rotation is a fundamental operation in red-black tree adjustments, used to maintain the balance of the tree. A right rotation promotes the left child to become the parent of the current node, and the current node becomes the right child of the new parent. The connections with the grandparent and the original left child need to be coordinated:

1. The right subtree of the left child is given to the parent as its left subtree.
2. The left child becomes the new parent, and the connection between the left child and the grandparent needs to be handled. (This is easier to understand with a diagram.)


#### 6. `inorderTraversal` Function

```cpp
void inorderTraversal(Node *node) const {
    if (node) {
        inorderTraversal(node->left);
        std::cout << node->key << " ";
        inorderTraversal(node->right);
    }
}
```

The inorder traversal function recursively traverses the tree in a left-middle-right order and prints the key values of the nodes. This traversal method prints all nodes in ascending order of key values.


#### 7. `insert` Function

```cpp
// Insert
  void insert(const Key &key) { insertNode(key); }
```

The public insertion interface takes a key value and uses the `insertNode` function to insert it into the tree.


#### 8. `deleteNode` Function

```cpp
void deleteNode(Node *del) {
  // ... (Code omitted for brevity) ...
}
```

In a red-black tree, the `deleteNode` function works by deleting a specified node while ensuring that all red-black tree properties remain intact. Deletion is generally more complex than insertion because it may require tree adjustments to maintain the red-black tree's balance properties.  The logic is detailed in the original description.


#### 9. `removeFixup` Function

```cpp
void removeFixup(Node *node) {
    // ... (Code omitted for brevity) ...
}
```

The `removeFixup` function in a red-black tree is called to restore the red-black tree properties after a node has been deleted from the tree.  The detailed logic is explained in the original description.


#### 10. Destructor `~RedBlackTree()` and `deleteTree` Function

```cpp
~RedBlackTree() {
    // Release node memory
    deleteTree(root);
}
void deleteTree(Node *node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}
```

The destructor is used to release the memory of all nodes in the red-black tree. It recursively calls the `deleteTree` function to release each node.
