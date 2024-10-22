// dijsktras.cpp

// Main Execution
#include <iostream>
#include <map>
#include <vector>

using namespace std;


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

    //read in the graph
    board.resize(gridSizeX*gridSizeY);
    for(int i = 0; i < gridSizeY; i++){
        for(int j = 0; j < gridSizeX; j++){
            cin >> tempChar;
            board[i*gridSizeY+j] = blockValues[tempChar];
        }
    }

    cin >> startX >> startY >> endX >> endY;
    return 0;
}

