#include <iostream>
#include <vector>
#include <utility>
using namespace std;


void dfs(int nd, int parent, int time, vector<int> &low, vector<int> &dis, vector<bool> &visited, vector<vector<int>> &graph, vector<pair<int, int>> &res) {
    visited[nd] = true;
    time++;
    dis[nd] = time;
    low[nd] = time;
    for (auto neighbor : graph[nd]) {
        if (neighbor == parent) continue;
        if (!visited[neighbor]) {
            dfs(neighbor, nd, time, low, dis, visited, graph, res);
            low[nd] = min(low[nd], low[neighbor]);
            if (low[neighbor] > dis[nd]) {
                res.push_back({nd, neighbor});
            }
        } else {
            low[nd] = min(low[nd], dis[neighbor]);
        }
    }
}

vector<vector<int>> buildGraph(int n, vector<pair<int, int>> &edges) {
    vector<vector<int>> graph(n + 1, vector<int> ());
    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graph;
}

vector<pair<int, int>> findBridges(int n, vector<pair<int, int>> &edges) {
    vector<vector<int>> graph = buildGraph(n, edges);
    vector<int> low(n + 1, -1);
    vector<int> dis(n + 1, -1);
    vector<bool> visited(n + 1, false);
    int time = 1;
    vector<pair<int, int>> res;
    dfs(1, -1, time, low, dis, visited, graph, res);
    return res;
}

void print_pair(vector<pair<int, int>> &p) {
    for (int i = 0; i < p.size(); ++i) {
        cout << p[i].first << "," << p[i].second << endl;
    }
}

int main() {
    cout << "graph" << endl;
    vector<pair<int, int>> edges;
    edges.push_back({1, 2});
    edges.push_back({1, 3});
    edges.push_back({3, 4});
    edges.push_back({1, 4});
    edges.push_back({4, 5});
    vector<pair<int, int>> res = findBridges(5, edges);
    print_pair(res);
    
    cout << "graph1" << endl;
    vector<pair<int, int>> edges1 = {{1, 2}, {1, 3}, {2, 3}, {3, 4}, {3, 6}, {4, 5}, {6, 7}, {6, 9}, {7, 8}, {8, 9}};
    vector<pair<int, int>> res1 = findBridges(9, edges1);
    print_pair(res1);

    cout << "graph2" << endl;
    vector<pair<int, int>> edges2 = {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {2, 5}, {4, 6}, {5, 6}};
    vector<pair<int, int>> res2 = findBridges(6, edges2);
    print_pair(res2);


}
