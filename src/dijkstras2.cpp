#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

// Struct to represent a node in the priority queue (cost, x-coordinate, y-coordinate)
struct Node {
    int cost;
    int x;
    int y;

    // Comparator to make the priority queue a min-heap (smallest cost first)
    bool operator>(const Node &other) const {
        return cost > other.cost;
    }
};

int main() {
    int numTileTypes;  // Number of different types of tiles
    char tileSymbol;   // Symbol representing a tile type
    int tileCost;      // Cost of moving through a tile

    // Read the number of tile types
    cin >> numTileTypes;

    // Map to store tile symbols and their corresponding movement costs
    map<char, int> blockValues;

    // Loop to read each tile type and its cost
    for (int i = 0; i < numTileTypes; i++) {
        cin >> tileSymbol >> tileCost;
        blockValues[tileSymbol] = tileCost;
    }

    // Variables to store the size of the grid (rows and columns)
    int gridSizeX, gridSizeY;
    cin >> gridSizeX >> gridSizeY;

    // Vector to store the cost for each tile in the grid
    vector<int> board(gridSizeX * gridSizeY);

    // Reading the grid and storing the cost of each tile based on its symbol
    for (int row = 0; row < gridSizeY; row++) {
        for (int col = 0; col < gridSizeX; col++) {
            cin >> tileSymbol;
            board[row * gridSizeX + col] = blockValues[tileSymbol];
        }
    }

    // Variables to store the start and end coordinates for the runner
    int startX, startY, endX, endY;
    cin >> startX >> startY >> endX >> endY;

    // Vector to store the shortest distance to each tile (initialized to infinity)
    vector<int> distances(gridSizeX * gridSizeY, INT_MAX);

    // Vector to store the parent of each tile for path reconstruction
    vector<pair<int, int>> parents(gridSizeX * gridSizeY, make_pair(-1, -1));

    // Vector to keep track of visited tiles
    vector<bool> visited(gridSizeX * gridSizeY, false);

    // Priority queue to implement Dijkstra's algorithm (min-heap)
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // Starting position (initialize the distance to 0 and add to the priority queue)
    distances[startY * gridSizeX + startX] = 0;
    pq.push({0, startX, startY});

    // Array of directions to move to adjacent tiles (right, down, left, up)
    int directionX[] = {0, 1, 0, -1};
    int directionY[] = {1, 0, -1, 0};

    // Dijkstra's algorithm
    while (!pq.empty()) {
        // Get the node with the smallest cost
        Node current = pq.top();
        pq.pop();

        int currentX = current.x;
        int currentY = current.y;
        int currentIdx = currentY * gridSizeX + currentX;

        // Skip this node if it has already been visited
        if (visited[currentIdx]) {
            continue;
        }

        visited[currentIdx] = true;

        // Stop if we reached the destination
        if (currentX == endX && currentY == endY) {
            break;
        }

        // Explore neighbors (adjacent tiles)
        for (int i = 0; i < 4; i++) {
            int newX = currentX + directionX[i];
            int newY = currentY + directionY[i];

            // Check if the new coordinates are within bounds
            if (newX >= 0 && newX < gridSizeX && newY >= 0 && newY < gridSizeY) {
                int newIdx = newY * gridSizeX + newX;
                int newCost = distances[currentIdx] + board[currentIdx];  // Apply cost of leaving the current tile

                // Update the distance and parent if a shorter path is found
                if (newCost < distances[newIdx]) {
                    distances[newIdx] = newCost;
                    parents[newIdx] = make_pair(currentX, currentY);
                    pq.push({newCost, newX, newY});
                }
            }
        }
    }

    // Path reconstruction
    vector<pair<int, int>> path;
    int currentX = endX;
    int currentY = endY;
    int endIdx = currentY * gridSizeX + currentX;
    int totalCost = distances[endIdx];

    // Trace the path backwards using the parent array
    while (currentX != -1 && currentY != -1) {
        path.push_back(make_pair(currentY, currentX));
        pair<int, int> parent = parents[currentY * gridSizeX + currentX];
        currentX = parent.first;
        currentY = parent.second;
    }

    // Output the total cost
    cout << totalCost << endl;

    // Output the path from start to end
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i].first << " " << path[i].second << endl;
    }

    return 0;
}