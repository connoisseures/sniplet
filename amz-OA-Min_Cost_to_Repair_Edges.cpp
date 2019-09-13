/*
Approach:
Time complexity: 
Space complexity: 
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <set> 
using namespace std;

int u_find(int nd, vector<int> parent) {
    if (nd == parent[nd]) return nd;
    parent[nd] = u_find(parent[nd], parent);
    return parent[nd];
}

int mst(int N, vector<vector<int>> &edges, vector<vector<int>> &edgesToRepair) {
    vector<int> parent(N + 1, 0);
    int component = N;
    vector<vector<int>> alledges;
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
    }
    set<vector<int>> hset; 
    for (auto e : edgesToRepair) {
        hset.insert({e[0], e[1]});
    }
    //define the cost of non repair edges. 
    for (auto e : edges) {
        if (hset.count({e[0], e[1]}) == 0) {
            alledges.push_back({e[0], e[1], 0});
        } 
    }
    //copy the cost of repair edges. 
    for (auto e : edgesToRepair) {
        alledges.push_back(e);
    }
    sort(alledges.begin(), alledges.end(), [](const vector<int> &a, const vector<int> &b){
        return a[2] < b[2];
    });
    int cost = 0;
    for (auto e : alledges) {
        int p1 = u_find(e[0], parent);
        int p2 = u_find(e[1], parent);
        if (p1 != p2) {
            parent[p2] = p1;
            cost += e[2];
            component--;
        }
    }
    return component == 1 ? cost : -1;
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5}};
    vector<vector<int>> edgesToRepair = {{1, 2, 12}, {3, 4, 30}, {1, 5, 8}};
    int cost = mst(n, edges, edgesToRepair);
    cout << cost << endl;

    int n1 = 6;
    vector<vector<int>> edges1 = {{1, 2}, {2, 3}, {4, 5}, {3, 5}, {1, 6}, {2, 4}};
    vector<vector<int>> edgesToRepair1 = {{1, 6, 410}, {2, 4, 800}};
    cout << mst(n1, edges1, edgesToRepair1) << endl;

    int n2 = 6;
    vector<vector<int>> edges2 = {{1, 2}, {2, 3}, {4, 5},{5, 6}, {1, 5}, {2, 4}, {3, 4}};
    vector<vector<int>> edgesToRepair2 = {{1, 5, 110}, {2, 4, 84}, {3, 4, 79}};
    cout << mst(n2, edges2, edgesToRepair2) << endl;
}
