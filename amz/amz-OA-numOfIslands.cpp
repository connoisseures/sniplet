#include <iostream>
#include <vector>
using namespace std;

/*
Thought:
We use DFS to traverse the grid from the positions with value as 1. 
When we are visiting the islands, we change the value of the position as 0. 
The number of DFS we applied to the grid is the number of the islands. 

Time complexity : O(m*n), where m is the row size of the grid and n is the column size of the grid
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid); 
                    res++;
                }
            }
        }
        return res;
    }
    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }
};


int main() {
    Solution sol;
    vector<vector<char>> islands = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}};
    int num = sol.numIslands(islands);
    cout << "case1" << endl;
    cout << num << endl;

    vector<vector<char>> islands1 = {
        {'1','1','0','1','0'},
        {'1','1','0','1','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','0'}};
    int num1 = sol.numIslands(islands1);
    cout << "case2" << endl;    
    cout << num1 << endl;

    vector<vector<char>> islands2 = {
        {'0','0','0','0','0'},
        {'0','0','0','0','0'},
        {'0','0','0','0','0'},
        {'0','0','0','0','0'}};
    int num2 = sol.numIslands(islands2);
    cout << "case3" << endl;    
    cout << num2 << endl;
}
