# Trees
The tree data structure is a non-linear data structure. Where each node contains data and can be linked to other nodes.

On the contrary data structures like Arrays, Linked Lists, Stacks and queues are linear data structures as each element follows follows one another in a linear fashion. Trees however, are different. In a tree, a single element can have multiple elements connected to each and brach out in different directions.

Such data structures are called tree as they look like one, but only upside down.

**Applications:** File systems, organizational models, database, routing data in network algorithms, sorting and searching data, priority queue.

**Properties:**
- A link connecting one node to another is called an **edge**.
- A **parent** node has links to its **child** nodes. Another word for a parent node is **internal** node.
- A node can have zero, one, or many child nodes.
- A node can only have one parent node.
- Nodes without links to other child nodes are called **leaves**, or **leaf nodes**.
- The tree **height** is the maximum number of edges from the root node to a leaf node. The height of the tree above is 2.
- The **height of a node** is the maximum number of edges between the node and a leaf node.
- The **tree size** is the number of nodes in the tree.

## Binary Trees
Binary tree is a type of tree data structure where each node can have maximum of two child nodes. Node on the left is called **left-node** and node on the right is called **right-node**.

**Benefits:**
- Faster traversing, searching, insertion and deletion.
- Sorted binary search tree (**BST**) makes searching very efficient.
- Balancing tee is easier with BST.
- BST can be represented as arrays, which makes it more memory efficient.

**Different binary trees:**
1. **Balanced**: A balanced binary tree has at most 1 in difference between its left and right subtree heights, for each node in the tree.
2. **Complete**: A complete binary tree has all levels full with nodes, except for the last level, which can also be full or filled from left to right. A complete binary tree means it's balanced too.
3. **Full**: A full binary tree is those who has either 0 or 2 child on each nodes.
4. **Perfect**: A perfect binary tree has all level filled up. By its properties it's also full, balanced and complete.

## Binary Search Trees
Binary search tree is a kind of data structure where every node's left child has a **lower** value, and right child has a **higher** value than its parent node.

**Properties:**
- Root node's left and its subtree should be **lower** than its root node.
- The right child and its subtree should be **higher** than its root.
- Left and right subtree both should be **binary search tree**.

## AVL Trees
The AVL tree is a self-balancing binary search tree. Meaning it automatically balances itself (*balanced binary tree*). It was named after its inventors **A**delson-**V**elsky and Evgenii **L**andis.

The only difference between a binary search tree and AVL tree is that AVL trees do **rotation** operations in addition to maintain the balance. By doing that AVL maintains a time complexity of **O(log n)** for insertion, search and deletion.

**Balance factor:** The balance factor (BF) of a node in an AVL tree is defined as:

*BF = height(left subtree) − height(right subtree)*
- If BF = 0 → left and right subtrees are the same height.
- If BF = +1 → left subtree is one level taller.
- If BF = -1 → right subtree is one level taller.
- If BF < -1 or BF > +1 → the node is unbalanced and requires rotation.

**Rotations:**
1. **Left-Left (LL):** The unbalanced node and its left child node are both left-heavy. A single right rotation is needed to restore balance.
2. **Right-Right (RR):** The unbalanced node and its right child node are both right-heavy. A single left rotation is needed.
3. **Left-Right (LR):** The unbalanced node is left heavy, and its left child node is right heavy. First do a left rotation on the left child node, then do a right rotation on the unbalanced node.
4. **Right-Left (RL):** The unbalanced node is right heavy, and its right child node is left heavy. First do a right rotation on the right child node, then do a left rotation on the unbalanced node.

**Retracing:** After inserting or deleting a node in an AVL tree, the tree may become unbalanced. To find out if the tree is unbalanced, we need to update the heights and recalculate the balance factors of all ancestor nodes. This process, known as retracing.
