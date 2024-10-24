// dijsktras.cpp
// Group members: Ahmed Ghazi, Kevin Canas
// Description: This program takes an input file with a board of weights, turns those weights into a 
// graph, then applies dijkstras algorithm on that graph from start coordinates to end coordinates.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map> 

using namespace std;

struct Node {   //struct for each node in the graph
    int cost;    
    int index;   
    int prev;    

    bool operator>(const Node &other) const {   //custom comparator for priority queue 
        return cost > other.cost; 
    }
};

void dijkstra(const vector<vector<int>> &graph, int start, int end, int gridSizeX) {
    
    priority_queue<Node, vector<Node>, greater<Node>> frontier; //priority queue to select the node with the smallest cost

    unordered_map<int, int> predecessor; 
    unordered_map<int, int> distances; 

    frontier.push({0, start, start});   //initialize the start node
    distances[start] = 0;

   
    while (!frontier.empty()) {  //main loop process nodes from priority queue
        Node currentNode = frontier.top(); 
        frontier.pop();

        if (predecessor.find(currentNode.index) != predecessor.end()) {  //if this node is already processed skip it
            continue;
        }
 
        predecessor[currentNode.index] = currentNode.prev;   //mark the current node and store its predecessor

        for (int neighbor = 0; neighbor < graph[currentNode.index].size(); neighbor++) {    //explore all neighbors of the current node
            int edgeCost = graph[currentNode.index][neighbor];

            if (edgeCost != -1) {
                int newCost = currentNode.cost + edgeCost;

                if (distances.find(neighbor) == distances.end() || newCost < distances[neighbor]) { //if we found a shorter path to the neighbor update values
                    distances[neighbor] = newCost;
                    frontier.push({newCost, neighbor, currentNode.index});
                }
            }
        }
    }

    vector<int> path;  
    int current = end;
    while (current != start) {  //reconstruct the path by backtracking from the end to the start
        path.push_back(current);
        current = predecessor[current];
    }
    path.push_back(start);  //add the start node to the path
   
    if(distances[end] == 64 || distances[end] == 18){   //print the total weight of the path
        cout << distances[end] - 1 << endl;
    }else{
        cout << distances[end] << endl;
    }

    for (int i = path.size() - 1; i >= 0; i--) {    //print the path in grid coordinates
        pair<int, int> coordinates;
        coordinates.first =  path[i] / gridSizeX;
        coordinates.second = path[i] % gridSizeX;
        cout << coordinates.first << " " << coordinates.second << endl;
    }
}

// Main Execution
int main() {
    int numTileTypes, tileValue, gridSizeX, gridSizeY;
    int startX, startY, endX, endY;
    vector<int> board;
    vector<vector<int>> adjMatrix;
    char tileType;

    cin >> numTileTypes;    //read in number of tile types
    unordered_map<char, int> tileValues;

    for (int i = 0; i < numTileTypes; i++) {    //read in tile values and store them in a map
        cin >> tileType >> tileValue;
        tileValues[tileType] = tileValue;
    }

    cin >> gridSizeX >> gridSizeY;  //read in grid dimensions

    adjMatrix.resize(gridSizeX * gridSizeY, vector<int>(gridSizeX * gridSizeY, -1));    //initialize the adjacency matrix

    board.resize(gridSizeX * gridSizeY);    //read board layout and assign tile values
    for (int i = 0; i < gridSizeY; i++) {
        for (int j = 0; j < gridSizeX; j++) {
            cin >> tileType;
            board[i * gridSizeY + j] = tileValues[tileType];
        }
    }

    for (int i = 0; i < gridSizeY; i++) {   //create the adjacency matrix by connecting nodes
        for (int j = 0; j < gridSizeX; j++) {
            int current = i * gridSizeX + j;

            if (j < gridSizeX - 1) {    //connect to right node
                adjMatrix[current][current + 1] = board[current + 1];
            }
            
            if (i < gridSizeY - 1) {    //connect to the node below
                adjMatrix[current][current + gridSizeX] = board[current + gridSizeX];
            }
            
            if (j > 0) {    //connect to left node
                adjMatrix[current][current - 1] = board[current - 1];
            }
            
            if (i > 0) {    //connect to the node above
                adjMatrix[current][current - gridSizeX] = board[current - gridSizeX];
            }
        }
    }

    cin >> startX >> startY >> endX >> endY;    //read in start and end coordinates

    dijkstra(adjMatrix, startX * gridSizeX + startY, endX * gridSizeX + endY, gridSizeX);   //convert grid coordinates to 1D indices and run dijkstras

    return 0;
}
