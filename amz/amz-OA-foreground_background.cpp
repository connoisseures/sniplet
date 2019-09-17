/*
Approach:
We consider all of the combination to find the one with optimal value.
Time complexity: We consider all of the combinations, so the time complexity is O(M*N)
Space complexity: We use a variable to track the maximal value, the space complexity is O(1) 
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> fg_bg_app_bruce_force(int capacity, vector<vector<int>> &fgApp, vector<vector<int>> &bgApp) {
    int max_val = INT_MIN;
    vector<vector<int>> res;
    for (int i = 0; i < fgApp.size(); ++i) {
        for (int j = 0; j < bgApp.size(); ++j) {
            if (fgApp[i][1] + bgApp[j][1] > capacity || 
            fgApp[i][1] + bgApp[j][1] < max_val) continue;
            if (fgApp[i][1] + bgApp[j][1] > max_val) {
                max_val = fgApp[i][1] + bgApp[j][1];
                res.clear();
            }
            res.push_back({fgApp[i][0], bgApp[j][0]});
        }
    }
    return res;
}

void print_vec(vector<vector<int>> &V) {
    //cout << V.size() << endl;
    for (int i = 0; i < V.size(); ++i) {
        cout << V[i][0] << "," << V[i][1] << endl;
    }
}

int main() {
    vector<vector<int>> fgApp = {{1,3}, {2,5}, {3,7}, {4,10}, {5,5}};
    //a = [[1, 3], [2, 5], [3, 7], [4, 10]]
    vector<vector<int>> bgApp = {{1,2}, {2,3}, {3,4}, {4,5}};
    //b = [[1, 2], [2, 3], [3, 4], [4, 5]]
    int cap = 10;
    vector<vector<int>> res = fg_bg_app_bruce_force(cap, fgApp, bgApp);
    print_vec(res);
}
