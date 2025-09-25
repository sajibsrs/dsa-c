# Graphs
A **graph** is a non-linear data structure consists of nodes (much like other node based data structures), but for graphs these nodes are called **vertices** (**vertex** singular). And the line connecting them are called edges (as usual).

**Applications:** Social networks, maps & navigation, internet, biology.

**Properties:**
- **Weighted:** Where the edges have values. The weight value of an edge can represent things like distance, capacity, time, or probability.
- **Connected:** When all the vertices are connected through edges somehow. A graph that is not connected, when it's isolated (disjoint) subgraphs, or single isolated vertices.
- **Directed:** When the edges between the vertex pairs have a direction, it's called **directed graph**, also known as a **digraph**. The direction of an edge can represent things like hierarchy or flow.
- **Cyclic:** When you can come back to the same vertex you started at without using the same edge more than once it's cyclic. This becomes little different when the graph is directed graph. As digraph has directions, the directions must match to make it circular.
- **Loop:** A loop, also called a self-loop, is an edge that begins and ends on the same vertex. A loop is a cycle that only consists of one edge.

## Adjacency Matrix
The adjacency matrix is a 2D array (matrix) where each cell on index (i,j) stores information about the edge from vertex i to vertex j.

**Example 1:** Say, we have a undirected graph, each vertex is labeled A,B,C,D. Where A connecting B,C,D. B connecting C. Since it's undirected and unweighted, we can describe this in matrix like:

Edges: A-B, A-C, A-D, B-C.
```terminal
    A B C D
  +--------
A | 0 1 1 1
B | 1 0 1 0
C | 1 1 0 0
D | 1 0 0 0
```

**Example 2:** Here we have node A which edge has a weight of 3 and direction A->B. Then A->C weight 2, D->A weight 4, C->B weight 1.

Edges: A-(3)->B, A-(2)->C, D-(4)->A, C-(1)->B.
```terminal
    A B C D
  +--------
A | 0 3 2 0
B | 0 0 0 0
C | 0 1 0 0
D | 4 0 0 0
```
While 2D array can be used in adjacency matrix, it wastes memory. As can be seen from the examples, most of the cells are empty. A better approach would be to use array and linked-list (hybrid) solution.

## Adjacency List
Here we have an array of the vertices A,B,C,D then linked-list nodes are attached to each one of them (if non-empty). The linked list node has a pointer to the index or the node it's connected to and a weight value (if it has any).

**Example 1:** We're using the same data from example 1 above (adjacency matrix).
```terminal
A [0]->[1]->[2]->[3]->null
B [1]->[0]->[2]->null
C [2]->[0]->[1]->null
D [3]->[0]
```

**Example 2:** We're using the same data from example 2 above (adjacency matrix).
```terminal
A [0]->[1],3->[2],2->null
B [1]->null
C [2]->[1],1->null
D [3]->[0],4->null
```
