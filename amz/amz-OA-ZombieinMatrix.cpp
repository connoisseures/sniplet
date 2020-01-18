#include <iostream>
#include <vector>
#include <queue>          // std::queue
using namespace std;

/*
we assume 
1. empty grid, output 0
2. empty zombie, output -1

Thought:
We use BFS to traverse the grid and start from the positions with its value as 1. 
We modify the value of the position we are visiting as 1 until we visit all of the grids. 

Time complexity:
T = O(m*n), where m is row size of grid, n is the column size of grid

Space complexity:
O(m*n)
*/

bool isValid(int i, int j, vector<vector<int>> &grid) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size()) return false;
    return true;
}

int timeOfInfecting(vector<vector<int>> grid) {
    if (grid.size() == 0 || grid[0].size() == 0) return 0; 
    int people = 0;
    int m = grid.size(), n = grid[0].size();
    queue<vector<int>> que;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            //cout << grid[i][j] << " ";
            if (grid[i][j] == 1) que.push({i,j});
            else if (grid[i][j] == 0) people++;
        }
        //cout << endl;
    }
    if (people == 0) return 0;
    //if (people == 0) return -1;

    int hours = 0;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    while (!que.empty()) {
        int sz = que.size();
        for (int i = 0; i < sz; ++i) {
            vector<int> crt = que.front();
            que.pop();
            for (int k = 0; k < dir.size(); ++k) {
                int x = crt[1] + dir[k][1];
                int y = crt[0] + dir[k][0];
                if (isValid(y, x, grid) && grid[y][x] == 0) {
                    grid[y][x] = 1;
                    que.push({y, x});
                    people--;
                }
            }
        }
        if (que.size() > 0) hours++;
    }
    return people == 0 ? hours : -1;
}

int main() {
    vector<vector<int>> grid = {
        {0, 1, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0}};
    int hours = timeOfInfecting(grid);
    cout << "case0" << endl;
    cout << "hours : " << hours << endl;

    cout << "case1: no people" << endl;
    vector<vector<int>> grid1 = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}};
    int hours1 = timeOfInfecting(grid1);
    cout << "hours : " << hours1 << endl;

    cout << "case2" << endl;
    vector<vector<int>> grid2 = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    int hours2 = timeOfInfecting(grid2);
    cout << "hours : " << hours2 << endl;

    cout << "case3" << endl;
    vector<vector<int>> grid3 = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    int hours3 = timeOfInfecting(grid3);
    cout << "hours : " << hours3 << endl;

    cout << "case4: no zombie" << endl;
    vector<vector<int>> grid4 = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    int hours4 = timeOfInfecting(grid4);
    cout << "hours : " << hours4 << endl;

    vector<vector<int>> grid5 = {
        {1}};
    int hours5 = timeOfInfecting(grid5);
    cout << "case5" << endl;
    cout << "hours : " << hours5 << endl;

    vector<vector<int>> grid6 = {
        {0}};
    int hours6 = timeOfInfecting(grid6);
    cout << "case6" << endl;
    cout << "hours : " << hours6 << endl;

    vector<vector<int>> grid7 = {
        {0,0}};
    int hours7 = timeOfInfecting(grid7);
    cout << "case7: 1d grid" << endl;
    cout << "hours : " << hours7 << endl;

    vector<vector<int>> grid8 = {
        {0,1}};
    int hours8 = timeOfInfecting(grid8);
    cout << "case8: 1d grid" << endl;
    cout << "hours : " << hours8 << endl;

    vector<vector<int>> grid9 = {
        {}};
    int hours9 = timeOfInfecting(grid9);
    cout << "case9: empty grid" << endl;
    cout << "hours : " << hours9 << endl;
}

