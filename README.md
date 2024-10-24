Project 04: Path Finding
========================

|  N   | Elapsed Time | Memory Usage |
|------|--------------|--------------|
| 10   | .0013        | 134,464      |
| 20   | .0023        | 168,256      |
| 50   | .0284        | 386,988      |
| 100  | .4063        | 974,026      |
| 200  | 6.9225       | 3,225,107    |
| 500  | 40.4063      | 18,699,438   |
| 1000 | 140.0775     | 78,738,080   |


Kevin Canas:

How did you represent the map as a graph?
The map was represented as an adjacency matrix, where each node corresponds to a cell on the grid. Each node is connected to its neighboring cells with a weighted edge.

What is the complexity of your implementation of Dijkstra's Algorithm?
The time complexity of our Dijkstra implementation is O(V^2), where V is the number of vertices (N^2 for an NxN map). We used a priority queue  to select the next node with the shortest distance and an adjacency matrix to represent the graph. The memory complexity is O(V^2) for storing the distances, predecessor, and other data structures.

How well does your implementation scale?
As the size of the map increases, both the execution time and memory usage grow significantly. this is because the number of nodes is N^2 and the number of edges increases accordingly. larger values of N result in longer processing times and higher memory consumption especially when N reaches 500 or 1000.

Contributions: Most of the work was done together in person or over discord using liveshare. Ahmed did most of the bug checking/fixing for dijkstras while Kevin worked on generate_map.cpp

Ahmed Ghazi:
How did you represent the map as a graph?
We used an adjacency matrix to representh the graph.

What is the complexity of Dijkstra's Algorithm?
The time complexity of Dijkstra's Algorithm is O(V^2). The space complexity is also O(V^2).

How well does your implementation scale?
As the number of columns and rows grows, the time and space used becomes very big very fast. This is due to our dijkstras space and time complexity being O(V^2) which scales up very fast.

Contributions: We worked in person and on discord for the entire project. We used a pair programming workflow to finish the project. Kevin wrote the generate_map.cpp since I was the driver seat in the 
pair programming for most of the project.
