#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> ReadBoardFile(string path) {
    ifstream myfile(path);
    vector<vector<int>> board{};
    int n;
    char c;

    if (myfile) {
        string line;
        while (getline(myfile, line)) {
            istringstream sline(line);
            vector<int> row;
            while (sline >> n >> c && c == ',') row.push_back(n);
            board.push_back(row);
        }
    }
    return board;
}

void PrintBoard(const vector<vector<int>> board, string path) {
    ofstream myfile(path);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++)
            myfile << board[i][j];
        myfile << "\n";
    }
    myfile.close();
}

int main() {
    auto board = ReadBoardFile("board.in");
    PrintBoard(board, "board.out");
}
