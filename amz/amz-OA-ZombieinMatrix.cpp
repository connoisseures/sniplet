#include <iostream>
#include <vector>
#include <queue>          // std::queue
using namespace std;


bool isValid(int i, int j, vector<vector<int>> &grid) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size()) return false;
    return true;
}

int timeOfInfecting(vector<vector<int>> grid) {
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
    //if (people == 0) return 0;
    if (people == 0) return -1;

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
    cout << "hours : " << hours << endl;

    vector<vector<int>> grid1 = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}};
    int hours1 = timeOfInfecting(grid1);
    cout << "hours : " << hours1 << endl;

    vector<vector<int>> grid2 = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    int hours2 = timeOfInfecting(grid2);
    cout << "hours : " << hours2 << endl;

    vector<vector<int>> grid3 = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    int hours3 = timeOfInfecting(grid3);
    cout << "hours : " << hours3 << endl;
}

