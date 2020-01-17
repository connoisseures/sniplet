#include <iostream>
#include <vector>
#include <unordered_set> 
#include <algorithm>
using namespace std;

/*
In DFS tree, a vertex u is parent of another vertex v, if v is discovered by u. 
In DFS tree, a vertex u is articulation point if one of the following two conditions is true.
1) u is root of DFS tree and it has at least two children.
2) u is not root of DFS tree and it has a child v such that no vertex in subtree rooted with v has a back edge to one of the ancestors (in DFS tree) of u.

https://cp-algorithms.com/graph/cutpoints.html#toc-tgt-0
*/

vector<vector<int>> buildGraph(int n, vector<pair<int, int>> &edges) {
    vector<vector<int>> graph(n, vector<int> ());
    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graph;
}

void dfs(int node, int parent, int &time, vector<int> &low, vector<int> &dis, vector<bool> &visited, vector<vector<int>> &graph, unordered_set<int> &res) {
    visited[node] = true;
    time++;
    dis[node] = time;
    low[node] = time;
    int children = 0;
    for(int i = 0; i < graph[node].size(); ++i) {
        int neighbor = graph[node][i];
        if (parent == neighbor) continue;
        if (visited[neighbor]) {
            low[node] = min(low[node], dis[neighbor]);
        } else {
            dfs(neighbor, node, time, low, dis, visited, graph, res);
            low[node] = min(low[node], low[neighbor]);
            if (low[neighbor] >= dis[node] && parent != -1) {
                res.insert(node);
            }
            children++;
        }
        if (parent == -1 && children > 1) {
            cout << "root: " << node << endl;
            res.insert(node);
        }
    } 
}

vector<int> findCutNode(int numNodes, vector<pair<int, int>> &edges) {
    vector<vector<int>> graph = buildGraph(numNodes, edges);
    vector<int> low(numNodes, -1);
    vector<int> dis(numNodes, -1);
    vector<bool> visited(numNodes, false);
    int time = 1;
    unordered_set<int> res;
    dfs(1, -1, time, low, dis, visited, graph, res);
    vector<int> cutNodes;
    for (auto it = res.begin(); it != res.end(); ++it) {
        cutNodes.push_back(*it);
    }
    sort(cutNodes.begin(), cutNodes.end());
    return cutNodes;
}

void print_vec(vector<int> v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "graph1" << endl;
    int numRouters1 = 7;
	vector<pair<int, int>> links1 = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 5}, {5, 6}, {3, 4}};
    vector<int> res1 = findCutNode(numRouters1, links1);
    print_vec(res1);

    cout << "graph2" << endl;
    int numRouters2 = 3;
	vector<pair<int, int>> links2 = {{0, 1}, {1, 2}, {2, 0}};
    vector<int> res2 = findCutNode(numRouters2, links2);
    print_vec(res2);
}
