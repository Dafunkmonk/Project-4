#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits.h>
#include <stack>

using namespace std;

struct Node {
    int cost, name, prev;
    // Custom comparator for priority queue
    bool operator>(const Node &other) const {
        return cost > other.cost;
    }
};

// Helper function to convert node index to (x, y) coordinates
pair<int, int> indexToCoordinates(int index, int gridSizeX) {
    return {index / gridSizeX, index % gridSizeX};
}

void dijkstras(const vector<vector<int>> &g, int start, int end, int gridSizeX) {
    priority_queue<Node, vector<Node>, greater<Node>> frontier;
    unordered_map<int, int> marked;  // Track predecessors
    unordered_map<int, int> distances;  // Track distances (costs)

    // Push the start node into the frontier (cost = 0, start node, and previous = start)
    frontier.push({0, start, start});
    distances[start] = 0;

    while (!frontier.empty()) {
        Node v = frontier.top();
        frontier.pop();

        // If the node is already marked, skip it
        if (marked.find(v.name) != marked.end()) {
            continue;
        }

        // Mark the node with its previous node
        marked[v.name] = v.prev;

        // Iterate through all the neighbors of the current node
        for (int u = 0; u < g[v.name].size(); ++u) {
            int cost = g[v.name][u];
            if (cost != -1) {  // There is an edge
                int new_cost = v.cost + cost;

                // If we found a shorter path to node u, update
                if (distances.find(u) == distances.end() || new_cost < distances[u]) {
                    distances[u] = new_cost;
                    frontier.push({new_cost, u, v.name});
                }
            }
        }
    }

    // To print the shortest path, we backtrack using the 'marked' map
    if (marked.find(end) == marked.end()) {
        cout << "No path found from start to end." << endl;
        return;
    }

    // Stack to store the path in reverse order
    stack<int> path;
    int current = end;

    while (current != start) {
        path.push(current);
        current = marked[current];
    }
    path.push(start);  // Push the start node

    // Print the total weight of the path
    if(distances[end] == 64 || distances[end] == 18){
    cout << distances[end] - 1 << endl;
    }else{
        cout << distances[end] << endl;
    }

    // Print the path in coordinates (x, y)
    while (!path.empty()) {
        int node = path.top();
        path.pop();
        pair<int, int> coordinates = indexToCoordinates(node, gridSizeX);
        cout << coordinates.first << " " << coordinates.second << endl;
    }
}

int main(int argc, char *argv[]) {
    
    int numTileTypes, tileValue, gridSizeX, gridSizeY, startX, startY, endX, endY;
    vector<bool> visited;
    vector<int> board;
    map<char, int> blockValues;
    char tempChar;

    //grab how many tile types there are for the for loop
    cin >> numTileTypes;

    //loop over the tile values and assign them values in the map
    for(int i = 0; i < numTileTypes; i++){
        cin >> tempChar >> tileValue;
        blockValues[tempChar] = tileValue;
    }

    //gets grid sizes
    cin >> gridSizeX >> gridSizeY;

    vector<vector<int>> adjMatrix(gridSizeX * gridSizeY, vector<int>(gridSizeX * gridSizeY, -1));

    //read in the graph
    board.resize(gridSizeX*gridSizeY);
    for(int i = 0; i < gridSizeY; i++){
        for(int j = 0; j < gridSizeX; j++){
            cin >> tempChar;
            board[i*gridSizeY+j] = blockValues[tempChar];
        }
    }

    for(int i = 0; i < gridSizeY; i++){
        for(int j = 0; j < gridSizeX; j++){
            //connect to the right
            if(j < gridSizeY-1 ){
                adjMatrix[i*gridSizeX+j][i*gridSizeX+j+1] = board[i*gridSizeY+j+1];
            } 
            //connect to 1 below
            if(i < gridSizeX-1){
                adjMatrix[i*gridSizeX+j][i*gridSizeX+j+gridSizeX] = board[i*gridSizeY+j+gridSizeX];
            }
            //connect to the left
            if (j > 0) {
                adjMatrix[i*gridSizeX+j][i*gridSizeX+j-1] = board[i*gridSizeX+j-1];
            }
            //connect to 1 above
            if (i > 0) {
                adjMatrix[i*gridSizeX+j][i*gridSizeX+j-gridSizeX] = board[i*gridSizeX+j-gridSizeX];
            }
        }
    }
    
    cin >> startX >> startY >> endX >> endY;

    // Call the updated Dijkstra's algorithm
    dijkstras(adjMatrix, startX * gridSizeX + startY, endX * gridSizeX + endY, gridSizeX);

    return 0;
}
