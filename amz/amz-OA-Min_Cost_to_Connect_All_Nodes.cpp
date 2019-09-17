/*
Approach: 

Time complexity: 

Space complexity: 

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int u_find(int nd, vector<int> &parent) {
    if (nd == parent[nd]) return nd;
    parent[nd] = u_find(parent[nd], parent);
    return parent[nd];
}

void u_union(int nd1, int nd2, vector<int> &parent, int &component) {
    int p1 = u_find(nd1, parent);
    int p2 = u_find(nd2, parent);
    if (p1 == p2) return;
    parent[p2] = p1;
    component--;
}

int mst(int N, vector<vector<int>> &edges, vector<vector<int>> &newEdges) {
    vector<int> parent(N + 1, 0);
    int component = N;
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
    }
    for (auto eg : edges) {
        u_union(eg[0], eg[1], parent, component);
    }
    sort(newEdges.begin(), newEdges.end(), [](const vector<int> &a, const vector<int> &b){
        return a[2] < b[2];
    });
    int cost = 0;
    for (auto e : newEdges) {
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
    int N = 6;
    vector<vector<int>> edges = {{1, 4}, {4, 5}, {2, 3}};
    vector<vector<int>> newEdges = {{1, 2, 5}, {1, 3, 10}, {1, 6, 2}, {5, 6, 5}};
    int cost = mst(N, edges, newEdges);
    cout << cost << endl;

}

