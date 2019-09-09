
/*
Approach:
We use a BFS(breadth-first search) to find the target. We also use a map to record the position we have visited. For a position, we put its neighbor in the queue if its neighbor is not visited or its value is not '0'. We continue the BFS search until we reach the target. The length of the path is the minimal path to reach the target. 
Time complexity: We at most check each position in the map. So the time complexity is O(M*N)
Space complexity: We use a map to record the visited position. So the space complexity is O(M*N)
*/


#include <iostream>
#include <vector>
#include <queue> 
using namespace std;
/*
https://aonecode.com/amazon-online-assessment-oa2-move-obstacle
*/

bool is_out_of_lot(vector<int> &nxt, int numRows, int numColumns) {
    if (nxt[0] < 0 || nxt[0] >= numRows || nxt[1] < 0 || nxt[1] >= numColumns) {
        return true;
    }
    return false;
}

int bfs(int numRows, int numColumns, vector<vector<int>> &lot) {
    if (lot.empty()) return -1;
    if (lot[0][0] == 9) return 0;
    if (lot[0][0] == 0) return -1;
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    queue<vector<int>> que;
    que.push({0,0});
    int cnt = 0;
    while (!que.empty()) {
        int sz = que.size();
        cnt++;
        for (int i = 0; i < sz; ++i) {
            vector<int> crt = que.front(); que.pop();   
            for (int k = 0; k < dir.size(); ++k) {
                vector<int> nxt(2, 0);
                nxt[0] = crt[0] + dir[k][0];
                nxt[1] = crt[1] + dir[k][1];
                if (is_out_of_lot(nxt, numRows, numColumns)) continue;
                if (lot[nxt[0]][nxt[1]] == 9) return cnt;
                if (lot[nxt[0]][nxt[1]] == 1) {
                    que.push(nxt);
                    lot[nxt[0]][nxt[1]] = 0;
                }
            }
        }
    }
    return cnt;
}

int bfs_wo_modify_lot(int numRows, int numColumns, vector<vector<int>> &lot) {
    if (lot.empty()) return -1;
    if (lot[0][0] == 9) return 0;
    if (lot[0][0] == 0) return -1;
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<bool>> visited(numRows, vector<bool> (numColumns, false));
    queue<vector<int>> que;
    que.push({0,0});
    visited[0][0] = true;
    int cnt = 0;
    while (!que.empty()) {
        int sz = que.size();
        cnt++;
        for (int i = 0; i < sz; ++i) {
            vector<int> crt = que.front(); que.pop();   
            for (int k = 0; k < dir.size(); ++k) {
                vector<int> nxt(2, 0);
                nxt[0] = crt[0] + dir[k][0];
                nxt[1] = crt[1] + dir[k][1];
                if (is_out_of_lot(nxt, numRows, numColumns) || visited[nxt[0]][nxt[1]]) continue;
                if (lot[nxt[0]][nxt[1]] == 9) return cnt;
                if (lot[nxt[0]][nxt[1]] == 1) {
                    que.push(nxt);
                    visited[nxt[0]][nxt[1]] = true;
                }
            }
        }
    }
    return cnt;
}

int main() {
    vector<vector<int>> lot = {{1, 0, 0}, {1, 0, 0}, {1, 9, 1}};
    int numColumns = lot[0].size();
    int numRows = lot.size();
    int res = bfs(numRows, numColumns, lot);
    cout << res << endl;

    vector<vector<int>> lot2 = {{1, 0, 0}, {1, 0, 0}, {1, 9, 1}};
    int res2 = bfs_wo_modify_lot(numRows, numColumns, lot2);
    cout << "v2 = " << res2 << endl;
}


