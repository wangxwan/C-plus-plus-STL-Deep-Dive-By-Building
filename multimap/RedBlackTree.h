#include <iostream>
#include <sstream>
#include <string>

enum class Color { RED, BLACK };

template <typename Key, typename Value> class RedBlackTree {
  class Node {
  public:
    Key key;
    Value value;
    Color color;
    Node *left;
    Node *right;
    Node *parent;

    // Constructor
    Node(const Key &k, const Value &v, Color c, Node *p = nullptr)
        : key(k), value(v), color(c), left(nullptr), right(nullptr), parent(p) {
    }
    Node()
        : color(Color::BLACK), left(nullptr), right(nullptr), parent(nullptr) {}
  };

private:
  Node *root;
  size_t size;
  Node *Nil;

  // Lookup a node
  Node *lookUp(Key key) {
    Node *cmpNode = root;

    while (cmpNode) {
      if (key < cmpNode->key) {
        cmpNode = cmpNode->left;
      } else if (key > cmpNode->key) {
        cmpNode = cmpNode->right;
      } else {
        return cmpNode;
      }
    }
    return cmpNode;
  }

  // Right rotation function
  void rightRotate(Node *node) {
    Node *l_son = node->left; // Get the left child of the current node

    // The left subtree of the current node becomes the right subtree of the left child
    node->left = l_son->right;
    // If the right subtree of the left child is not empty, update its parent pointer
    if (l_son->right) {
      l_son->right->parent = node;
    }

    // The left child moves up to the current node's position, and the parent relationship is handled
    l_son->parent = node->parent;
    // If the current node is the root node, update the root node to the left child
    if (!node->parent) {
      root = l_son;
      // If the current node is the left child of its parent node, update the parent node's left child to the left child
    } else if (node == node->parent->left) {
      node->parent->left = l_son;
      // If the current node is the right child of its parent node, update the parent node's right child to the left child
    } else {
      node->parent->right = l_son;
    }

    // Complete the right rotation, making the current node the right child of the left child
    l_son->right = node;
    // Update the parent of the current node to the left child
    node->parent = l_son;
  }

  // Left rotation
  // Symmetrical to right rotation, the logic is the same
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

  // Insertion fixup function
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

  // Node insertion function
  void insertNode(const Key &key, const Value &value) {
    // Create a new node, and initialize the node's color to red
    Node *newNode = new Node(key, value, Color::RED);
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

  // Inorder traversal
  void inorderTraversal(Node *node) const {
    if (node) {
      inorderTraversal(node->left);
      std::cout << node->key << " ";
      std::cout << node->value << " ";
      inorderTraversal(node->right);
    }
  }
  // Helper function to replace an old node with a new node
  void replaceNode(Node *targetNode, Node *newNode) {
    if (!targetNode->parent) {
      root = newNode;
    } else if (targetNode == targetNode->parent->left) {
      targetNode->parent->left = newNode;
    } else {
      targetNode->parent->right = newNode;
    }
    if (newNode) {
      newNode->parent = targetNode->parent;
    }
  }

  // Find the minimum node in the subtree rooted at a given node
  Node *findMinimumNode(Node *node) {
    while (node->left) {
      node = node->left;
    }
    return node;
  }

  // removeFixup function is used to restore the properties of the red-black tree after deleting a node
  void removeFixup(Node *node) {
    // If the node is Nil and has no parent node, it means it is the only node, so return directly
    if (node == Nil && node->parent == nullptr) {
      return;
    }

    // Continue the loop when we haven't reached the root node
    while (node != root) {
      // If the node is the left child of its parent node
      if (node == node->parent->left) {
        // The sibling node is the right child of the node's parent
        Node *sibling = node->parent->right;

        // Case 1: The node's sibling node is red
        if (getColor(sibling) == Color::RED) {
          // Recolor the sibling node and parent node, and perform a left rotation
          setColor(sibling, Color::BLACK);
          setColor(node->parent, Color::RED);
          leftRotate(node->parent);
          // Update the sibling node after rotation
          sibling = node->parent->right;
        }

        // Case 2: Both children of the sibling node are black
        if (getColor(sibling->left) == Color::BLACK &&
            getColor(sibling->right) == Color::BLACK) {
          // Recolor the sibling node and move up
          setColor(sibling, Color::RED);
          node = node->parent;
          // If the parent node is red, change it to black and end
          if (node->color == Color::RED) {
            node->color = Color::BLACK;
            node = root;
          }
        } else {
          // Case 3: The right child of the sibling node is black (the left child is red)
          if (getColor(sibling->right) == Color::BLACK) {
            // Recolor the sibling node and the left child of the sibling node, and perform a right rotation
            setColor(sibling->left, Color::BLACK);
            setColor(sibling, Color::RED);
            rightRotate(sibling);
            // Update the sibling node after rotation
            sibling = node->parent->right;
          }

          // Case 4: The right child of the sibling node is red
          setColor(sibling, getColor(node->parent));
          setColor(node->parent, Color::BLACK);
          setColor(sibling->right, Color::BLACK);
          leftRotate(node->parent);
          // Move to the root node to end
          node = root;
        }
      } else {
        // When the node is the right child of its parent node, it's a symmetrical case
        Node *sibling = node->parent->left;

        if (getColor(sibling) == Color::RED) {
          setColor(sibling, Color::BLACK);
          setColor(node->parent, Color::RED);
          rightRotate(node->parent);
          sibling = node->parent->left;
        }

        if (getColor(sibling->right) == Color::BLACK &&
            getColor(sibling->left) == Color::BLACK) {
          setColor(sibling, Color::RED);
          node = node->parent;
          if (node->color == Color::RED) {
            node->color = Color::BLACK;
            node = root;
          }
        } else {
          if (getColor(sibling->left) == Color::BLACK) {
            setColor(sibling->right, Color::BLACK);
            setColor(sibling, Color::RED);
            leftRotate(sibling);
            sibling = node->parent->left;
          }
          setColor(sibling, getColor(node->parent));
          setColor(node->parent, Color::BLACK);
          setColor(sibling->left, Color::BLACK);
          rightRotate(node->parent);
          node = root;
        }
      }
    }
    // Ensure that the current node is black to maintain the red-black tree properties
    setColor(node, Color::BLACK);
  }

  // Get color, nullptr is black
  Color getColor(Node *node) {
    if (node == nullptr) {
      return Color::BLACK;
    }
    return node->color;
  }

  void setColor(Node *node, Color color) {
    if (node == nullptr) {
      return;
    }
    node->color = color;
  }

  // Disconnect the Nil sentinel node
  void dieConnectNil() {
    if (Nil == nullptr) {
      return;
    }
    if (Nil->parent != nullptr) {
      if (Nil == Nil->parent->left) {
        Nil->parent->left = nullptr;
      } else {
        Nil->parent->right = nullptr;
      }
    }
  }

  // Delete node
  void deleteNode(Node *del) {
    Node *rep = del; // rep (replacement node) initially points to the node to be deleted
    Node *child = nullptr;      // Child node of the node to be deleted
    Node *parentRP;             // Parent node of the replacement node
    Color origCol = rep->color; // Save the original color of the node to be deleted

    // If the node to be deleted has no left child
    if (!del->left) {
      rep = del->right;        // The replacement node points to the right child of the deleted node
      parentRP = del->parent;  // Update the parent node of the replacement node
      origCol = getColor(rep); // Get the color of the replacement node
      replaceNode(del, rep);   // Replace the deleted node with the replacement node
    }
    // If the node to be deleted has no right child
    else if (!del->right) {
      rep = del->left;         // The replacement node points to the left child of the deleted node
      parentRP = del->parent;  // Update the parent node of the replacement node
      origCol = getColor(rep); // Get the color of the replacement node
      replaceNode(del, rep);   // Replace the deleted node with the replacement node
    }
    // If the node to be deleted has two children
    else {
      rep = findMinimumNode(
          del->right); // Find the minimum node in the right subtree of the deleted node as the replacement node
      origCol = rep->color; // Save the original color of the replacement node
      // If the replacement node is not the direct right child of the deleted node
      if (rep != del->right) {
        parentRP = rep->parent; // Update the parent node of the replacement node
        child = rep->right; // The right child of the replacement node becomes the child node to be processed
        parentRP->left =
            child; // The left child of the parent node of the replacement node points to the child of the replacement node (because the replacement node is the minimum node, it is impossible to have a left child)
        if (child != nullptr) {
          child->parent = parentRP; // If the child of the replacement node exists, update its parent node
        }
        // Put the replacement node in the position of the deleted node
        del->left->parent = rep;
        del->right->parent = rep;
        rep->left = del->left;
        rep->right = del->right;
        // If the deleted node has a parent node, update the child pointer of the parent node
        if (del->parent != nullptr) {
          if (del == del->parent->left) {
            del->parent->left = rep;
            rep->parent = del->parent;
          } else {
            del->parent->right = rep;
            rep->parent = del->parent;
          }
        }
        // If the deleted node has no parent node, it means it is the root node
        else {
          root = rep;
          root->parent = nullptr;
        }
      }
      // If the replacement node is the direct right child of the deleted node
      else {
        child = rep->right; // The child node points to the right child of the replacement node
        rep->left = del->left; // The left child of the replacement node points to the left child of the deleted node
        del->left->parent = rep; // Update the parent node of the left child
        // Update the child pointer of the parent node of the deleted node
        if (del->parent != nullptr) {
          if (del == del->parent->left) {
            del->parent->left = rep;
            rep->parent = del->parent;
          } else {
            del->parent->right = rep;
            rep->parent = del->parent;
          }
        }
        // If the deleted node is the root node
        else {
          root = rep;
          root->parent = nullptr;
        }
        parentRP = rep; // Update the parent node of the replacement node
      }
    }

    // If the replacement node exists, update its color to the color of the deleted node
    if (rep != nullptr) {
      rep->color = del->color;
    }
    // If the replacement node does not exist, assign the color of the deleted node to the origCol variable
    else {
      origCol = del->color;
    }

    // If the original color is black, additional fixup operations are needed because the deletion of a black node may break the properties of the red-black tree
    if (origCol == Color::BLACK) {
      // If a child node exists, perform fixup operations
      if (child != nullptr) {
        removeFixup(child);
      }
      // If no child node exists, set the parent node of the Nil node (representing an empty node) to the parent node of the replacement node
      else {
        Nil->parent = parentRP;
        // If the parent node of the replacement node exists, set its corresponding child pointer to the Nil node
        if (parentRP != nullptr) {
          if (parentRP->left == nullptr) {
            parentRP->left = Nil;
          } else {
            parentRP->right = Nil;
          }
        }
        // Perform fixup operations
        removeFixup(Nil);
        // Disconnect the Nil node from the tree, because in a red-black tree, the Nil node is usually separate
        dieConnectNil();
      }
    }

    // Delete the node
    delete del;
  }

public:
  // Constructor
  RedBlackTree() : root(nullptr), size(0), Nil(new Node()) {
    Nil->color = Color::BLACK;
  }

  // Insert
  void insert(const Key &key, const Value &value) { insertNode(key, value); }

  // Delete
  void remove(const Key &key) {
    Node *nodeToBeRemoved = lookUp(key);
    if (nodeToBeRemoved != nullptr) {
      deleteNode(nodeToBeRemoved);
      size--;
    }
  }

  Value *at(const Key &key) {
    auto ans = lookUp(key);
    if (ans != nullptr) {
      return &ans->value;
    }
    return nullptr;
  }

  int getSize() { return size; }

  bool empty() { return size == 0; }

  // Inorder traversal print
  void print() {
    inorderTraversal(root);
    std::cout << std::endl;
  }

  void clear() {
    deleteNode(root);
    size = 0;
  }

  // Destructor
  ~RedBlackTree() {
    // Release node memory
    deleteTree(root);
  }

private:
  // Recursively release node memory
  void deleteTree(Node *node) {
    if (node) {
      deleteTree(node->left);
      deleteTree(node->right);
      delete node;
    }
  }
};

