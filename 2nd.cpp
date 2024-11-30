#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
vector<string> extractGrid(const vector<string>& inputGrid, int startcol) {
    vector<string> gridSlice;
    for (int i = 0; i < 9; i++) {
        gridSlice.push_back(inputGrid[i].substr(startcol, 5));
    }
    return gridSlice;
}
bool isZeroPaddingcol(const vector<string>& inputGrid, int col) {
    for (int i = 0; i < 9; i++) {
        if (inputGrid[i][col] != '0') return false;
    }
    return true;
}
map<vector<string>, char> generatealphaMap() {
    map<vector<string>, char> alphaMap;
    
    // Manually mapping each 9x5 grid pattern to a corresponding alphabet
    alphaMap[{"11111", "10001", "10001", "10001","11111", "10001", "10001", "10001", "10001"}] = 'A';
    alphaMap[{"11111", "10001", "10001", "10001", "11111", "10001", "10001", "10001", "11111"}] = 'B';
    alphaMap[{"11111", "10000", "10000", "10000", "10000", "10000", "10000", "10000", "11111"}] = 'C';
    alphaMap[{"11111", "10001", "10001", "10001", "10001", "10001", "10001", "10001", "11111"}] = 'D';
    alphaMap[{"11111", "10000", "10000", "10000", "11111", "10000", "10000", "10000", "11111"}] = 'E';
    alphaMap[{"11111", "10000", "10000", "10000", "11111", "10000", "10000", "10000", "10000"}] = 'F';
    alphaMap[{"11111", "10000", "10000", "10000", "10111", "10001", "10001", "10001", "11111"}] = 'G';
    alphaMap[{"10001", "10001", "10001", "10001", "11111", "10001", "10001", "10001", "10001"}] = 'H';
    alphaMap[{"11111", "00100", "00100", "00100", "00100", "00100", "00100", "00100", "11111"}] = 'I';
    alphaMap[{"11111", "00001", "00001", "00001", "10001", "10001", "10001", "10001", "11111"}] = 'J';
    alphaMap[{"10001", "10010", "10100", "11000", "11111", "10001", "10001", "10001", "10001"}] = 'K';
    alphaMap[{"10000", "10000", "10000", "10000", "10000", "10000", "10000", "10000", "11111"}] = 'L';
    alphaMap[{"11111", "10101", "10101", "10101", "10101", "10001", "10001", "10001", "10001"}] = 'M';
    alphaMap[{"10001", "11001", "10101", "10011", "10001", "10001", "10001", "10001", "10001"}] = 'N';
    alphaMap[{"01110", "10001", "10001", "10001", "10001", "10001", "10001", "10001", "01110"}] = 'O';
    alphaMap[{"11111", "10001", "10001", "10001", "11111", "10000", "10000", "10000", "10000"}] = 'P';
    alphaMap[{"11111", "10001", "10001", "10001", "10101", "10001", "10011", "10001", "11111"}] = 'Q';
    alphaMap[{"11111", "10001", "10001", "10001", "11111", "11000", "10100", "10010", "10001"}] = 'R';
    alphaMap[{"11111", "10000", "10000", "10000", "11111", "00001", "00001", "00001", "11111"}] = 'S';
    alphaMap[{"11111", "00100", "00100", "00100", "00100", "00100", "00100", "00100", "00100"}] = 'T';
    alphaMap[{"10001", "10001", "10001", "10001", "10001", "10001", "10001", "10001", "11111"}] = 'U';
    alphaMap[{"10001", "10001", "10001", "10001", "10001", "10001", "10001", "01010", "00100"}] = 'V';
    alphaMap[{"10001", "10001", "10001", "10001", "10101", "10101", "10101", "10101", "11111"}] = 'W';
    alphaMap[{"10001", "00000", "01010", "00000", "00100", "00000", "01010", "00000", "10001"}] = 'X';
    alphaMap[{"10001", "10001", "10001", "10001", "11111", "00001", "00001", "00001", "11111"}] = 'Y';
    alphaMap[{"11111", "00000", "00010", "00000", "00100", "00000", "01000", "00000", "11111"}] = 'Z';

    return alphaMap;
}

int main() {
    vector<string> inputGrid(9);
    for (int i = 0; i < 9; i++) {
        cin >> inputGrid[i];
    }

    map<vector<string>, char> alphaMap = generatealphaMap();
    string output;
    int curcol = 0;
    int totalcols = inputGrid[0].size();

    while (curcol < totalcols) {
        while (curcol < totalcols && isZeroPaddingcol(inputGrid, curcol)) {
            curcol++;
        }
        if (curcol + 5 <= totalcols) {
            vector<string> gridSlice = extractGrid(inputGrid, curcol);

            if (alphaMap.count(gridSlice)) {
                output += alphaMap[gridSlice];
            }
            curcol += 5;
        }
    }
    cout << output;
    return 0;
}
