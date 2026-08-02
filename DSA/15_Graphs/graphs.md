# Graphs - Basics

## 1. Introduction to Graphs

A **graph** is a non-linear data structure used to represent relationships between objects.

A graph consists of:

* **Vertices (Nodes)** → The objects/entities in the graph.
* **Edges** → The connections/relationships between vertices.

A graph is represented as:

[
G = (V, E)
]

where:

* `V` = set of vertices
* `E` = set of edges

Example:

```
     A
    / \
   B---C
```

Vertices:

```
V = {A, B, C}
```

Edges:

```
E = {(A,B), (A,C), (B,C)}
```

---

# 2. Graph Terminologies

## Vertex (Node)

A fundamental unit of a graph.

Example:

```
A ---- B
```

`A` and `B` are vertices.

---

## Edge

A connection between two vertices.

Example:

```
A ------ B
```

The edge is:

```
(A,B)
```

---

## Adjacent Vertices

Two vertices are adjacent if there is an edge between them.

Example:

```
A ----- B
```

A and B are adjacent.

---

## Degree of a Vertex

The number of edges connected to a vertex.

Example:

```
       B
       |
A ---- C ---- D
```

Degree of C:

```
degree(C) = 3
```

---

## Indegree

Number of incoming edges.

Used in directed graphs.

Example:

```
A ---> B ---> C
```

Indegree of C:

```
1
```

---

## Outdegree

Number of outgoing edges.

Example:

```
A ---> B ---> C
```

Outdegree of A:

```
1
```

---

## Path

A sequence of vertices connected by edges.

Example:

```
A ---- B ---- C ---- D
```

Path:

```
A -> B -> C -> D
```

---

## Cycle

A path where the starting and ending vertices are the same.

Example:

```
A ---- B
|      |
D ---- C
```

Cycle:

```
A -> B -> C -> D -> A
```

---

## Connected Graph

A graph where every vertex can be reached from every other vertex.

Example:

```
A --- B --- C
```

All nodes are connected.

---

## Disconnected Graph

A graph containing multiple components.

Example:

```
A --- B

C --- D
```

Two separate components.

---

## Component

A connected part of a disconnected graph.

Example:

```
A---B     C---D
```

Components:

```
{A,B}
{C,D}
```

---

# 3. Types of Graphs

## 1. Undirected Graph

Edges have no direction.

Example:

```
A ----- B
```

Means:

```
A is connected to B
B is connected to A
```

Representation:

```
(A,B)
```

---

## 2. Directed Graph (Digraph)

Edges have direction.

Example:

```
A ----> B
```

Means:

```
A can go to B
```

but:

```
B cannot go to A
```

---

## 3. Weighted Graph

Edges have weights/costs.

Example:

```
A ----5---- B
```

Weight:

```
5
```

Used in:

* Shortest path algorithms
* Network routing

---

## 4. Unweighted Graph

Edges do not contain weights.

Example:

```
A ----- B
```

---

## 5. Cyclic Graph

Contains at least one cycle.

Example:

```
A ---> B
^     |
|     v
D <--- C
```

---

## 6. Acyclic Graph

Contains no cycles.

Example:

```
A ---> B ---> C
```

---

## 7. DAG (Directed Acyclic Graph)

A directed graph with no cycles.

Example:

```
A ---> B ---> C
```

Applications:

* Scheduling
* Dependency resolution

---

# 4. Bipartite Graph

A graph is called **bipartite** if its vertices can be divided into two sets such that:

* No two vertices in the same set are connected.
* Every edge connects vertices from different sets.
* bipartite graph can never contain an odd-length cycle.

Example:

```
Set A          Set B

  1 ------------ 4

  2 ------------ 5

  3 ------------ 6
```

Sets:

```
A = {1,2,3}

B = {4,5,6}
```

There are no edges:

```
1-2
2-3
1-3
```

inside the same group.

---

## Checking Bipartite Graph

A graph is bipartite if it can be colored using only two colors.

Example:

```
Red     Blue

A  ----- B
|        |
C  ----- D
```

Colors:

```
A = Red
B = Blue
C = Blue
D = Red
```

If two connected nodes get the same color:

```
Not Bipartite
```

---

## Bipartite Graph Applications

* Matching problems
* Job assignment
* Network flow
* Recommendation systems

---

# 5. Graph Representation

There are mainly two ways:

1. Adjacency Matrix
2. Adjacency List

---

# Adjacency Matrix

A 2D matrix representation.

For `n` vertices:

```
n x n matrix
```

Example:

Graph:

```
0 ---- 1
|
2
```

Matrix:

```
    0 1 2

0   0 1 1
1   1 0 0
2   1 0 0
```

If:

```
matrix[i][j] = 1
```

there is an edge between i and j.

---

## Weighted Graph Matrix

Instead of 1:

```
matrix[i][j] = weight
```

Example:

```
0  5  2
5  0  0
2  0  0
```

---

## Complexity

Space:

```
O(V²)
```

Checking edge:

```
O(1)
```

Adding edge:

```
O(1)
```

Best for:

* Dense graphs
* Small number of vertices

---

# Adjacency List

Each vertex stores its neighbours.

Example:

Graph:

```
0 ---- 1
|
2
```

Representation:

```
0 -> 1 -> 2

1 -> 0

2 -> 0
```

---

## Complexity

Space:

```
O(V + E)
```

Checking edge:

```
O(degree of vertex)
```

Adding edge:

```
O(1)
```

Best for:

* Sparse graphs
* Most competitive programming problems

---

# 6. BFS (Breadth First Search)

BFS explores graph level by level.

Uses:

```
Queue
```

Example:

```
        A
      /   \
     B     C
    /
   D
```

BFS order:

```
A B C D
```

---

## BFS Algorithm

1. Start from a source node.
2. Mark it visited.
3. Push it into queue.
4. Remove node from queue.
5. Visit all unvisited neighbours.
6. Repeat.

---

## BFS Code

```cpp
void bfs(int start, vector<int> adj[]) {

    queue<int> q;
    vector<bool> visited(V,false);

    q.push(start);
    visited[start]=true;

    while(!q.empty()){

        int node=q.front();
        q.pop();

        cout<<node<<" ";

        for(auto neighbour: adj[node]){

            if(!visited[neighbour]){

                visited[neighbour]=true;
                q.push(neighbour);

            }
        }
    }
}
```

---

## BFS Complexity

Using adjacency list:

Time:

```
O(V + E)
```

Space:

```
O(V)
```

---

# 7. DFS (Depth First Search)

DFS explores as deep as possible before backtracking.

Uses:

* Recursion
* Stack

Example:

```
        A
      /   \
     B     C
    /
   D
```

Possible DFS:

```
A B D C
```

---

## DFS Algorithm

1. Mark current node visited.
2. Print node.
3. Visit every unvisited neighbour recursively.

---

## DFS Code

```cpp
void dfs(int node, vector<int> adj[], vector<int>& visited){

    visited[node]=true;

    cout<<node<<" ";

    for(auto neighbour: adj[node]){

        if(!visited[neighbour])
            dfs(neighbour,adj,visited);

    }
}
```

---

## DFS Complexity

Time:

```
O(V + E)
```

Space:

```
O(V)
```

---

# 8. BFS vs DFS

| BFS                                     | DFS                      |
| --------------------------------------- | ------------------------ |
| Uses Queue                              | Uses Stack/Recursion     |
| Level order traversal                   | Depth traversal          |
| Finds shortest path in unweighted graph | Used for cycle detection |
| More memory                             | Less memory generally    |

---

# 9. Common Graph Algorithms

## Shortest Path

Algorithms:

* BFS (unweighted graph)
* Dijkstra (positive weights)
* Bellman Ford (negative weights)
* Floyd Warshall (all pairs)

---

## Minimum Spanning Tree

Algorithms:

* Kruskal
* Prim

---

## Cycle Detection

Using:

* DFS
* BFS
* Union Find

---

## Topological Sorting

Used in:

* DAG
* Scheduling problems

Methods:

* DFS
* Kahn's Algorithm (BFS)