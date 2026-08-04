#include <bits/stdc++.h>
using namespace std;

struct triple {
    int start_node;
    int end_node;
    int t;
};

int house_selector(int n, vector<int>& flats, vector<triple>& connections) {
    vector<vector<pair<int, int>>> adj(n); //adjacency list adj[node] = list of {neighbor_node, time_cost}
    for (const auto& edge: connections) {
        adj[edge.start_node].push_back({edge.end_node, edge.t});
        adj[edge.end_node].push_back({edge.start_node, edge.t});
    }
    vector<int> time(n, INT_MAX);
    time[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min pq
    pq.push({0,0}); //cur time, node

    while (!pq.empty()) {
        auto [cur_time, u] = pq.top();
        pq.pop();

        if (cur_time > time[u]) continue; //faster way to node, skip

        for (const auto & neighbor: adj[u]) { //check neighboring flats
            int v = neighbor.first;
            int weight = neighbor.second;
            if (time[u] + weight < time[v]) {
                time[v] = time[u] + weight;
                pq.push({time[v], v});
            }
        }
    }

    int minflat = -1;
    int cur_t = INT_MAX;

    for (int i = 0; i < flats.size(); i++) {
        int t = time[flats[i]];
        if (t < cur_t) {
            minflat = flats[i];
            cur_t = t;
        }
    }

    return minflat;

}
