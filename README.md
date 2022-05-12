## Complexity Analysis file
Read the file complexity_analysis to understand the complexity of the algrithm

## How to compile the code
i.e make

## How to Run  the code
```
./tarjan_cut_vertices

Input Graph
0,1,2,3,4,5,6 represents A,B,C,D,E,F,G respectively

Graph with 5 verticies
addEdge(adj1, 1, 0);
addEdge(adj1, 0, 2);
addEdge(adj1, 2, 1);
addEdge(adj1, 0, 3);
addEdge(adj1, 3, 4);

Graph with 4 verticies
addEdge(adj2, 0, 1);
addEdge(adj2, 1, 2);
addEdge(adj2, 2, 3);

Graph with 7 verticies
addEdge(adj3, 0, 1);
addEdge(adj3, 1, 2);
addEdge(adj3, 2, 0);
addEdge(adj3, 1, 3);
addEdge(adj3, 1, 4);
addEdge(adj3, 1, 6);
addEdge(adj3, 3, 5);
addEdge(adj3, 4, 5);


Sample Output File
Articulation points in first graph
0 3

Articulation points in second graph
1 2

Articulation points in third graph
1

