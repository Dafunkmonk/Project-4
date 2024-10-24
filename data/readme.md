| N    | Elapsed Time | Memory Usage |
|------|--------------|--------------|
| 10   | .0013        | 134,464      |
| 20   | .0023        | 168,256      |
| 50   | .0114        | 386,988      |
| 100  | .0463        | 974,026      |
| 200  | .0925        | 3,225,107    |
| 500  | .4063        | 14,699,438   |
| 1000 | 2.077        | 60,738,080   |

How did you represent the map as a graph?

The map was represented as an adjacency matrix, where each node corresponds to a cell on the grid. Each node is connected to its neighboring cells with a weighted edge where the weights were randomly generated between 1 and 10. the relationship between vertices was determined by the adjacency matrix with valid edges representing connections between neighboring cells.

What is the complexity of your implementation of Dijkstra's Algorithm?

The time complexity of our Dijkstra implementation is O((V + E) log V), where V is the number of vertices (N^2 for an NxN map) and E is the number of edges. we used a priority queue  to select the next node with the shortest distance and an adjacency matrix to represent the graph. the memory complexity is O(V) for storing the distances, predecessor, and other data structures.

How well does your implementation scale?

As the size of the map increases, both the execution time and memory usage grow significantly. this is because the number of nodes is N^2 and the number of edges increases accordingly. larger values of N result in longer processing times and higher memory consumption especially when N reaches 500 or 1000. the adjacency matrix representation consumes a large amount of memory as N increases.  

Contributions: Most of the work was done together in person or over discord using liveshare. Ahmed did most of the bug checking/fixing for dijkstras while i worked on generate_map.cpp