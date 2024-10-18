// dijsktras.cpp

// Main Execution
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
    
    int numTileTypes, tileValue, gridSizeX, gridSizeY, startX, startY, endX, endY;

    //grab how many tile types there are for the for loop
    cin >> numTileTypes;

    map<char, int> blockValues;

    char tempChar;

    //loop over the tile values and assign them values in the map
    for(int i = 0; i < numTileTypes; i++){
        cin >> tempChar >> tileValue;
        blockValues[tempChar] = tileValue;
    }

    //gets grid sizes
    cin >> gridSizeX >> gridSizeY;

    //read in the graph
    for(int i = 0; i < gridSizeY; i++){
        for(int j = 0; j < gridSizeX; j++){

        }
    }

    cin >> startX >> startY >> endX >> endY;
    return 0;
}

