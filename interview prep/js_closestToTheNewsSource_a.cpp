#include <bits/stdc++.h>
using namespace std;
struct triple {
    int start_node;
    int end_node;
    int t;
};
//tower = 0, flats 1, 2, 3...
//assume connections is sorted by start_node, t, and then end_node. so ready for bfs
int house_selector(vector<int>flats, vector<triple> connections) { //returns affordable flat with fastest connection
    vector<int> time(n, INT.MAXVALUE);
    time[0] = 0;

    for (int i = 0; i < connections.size(); i++) {
        int t = time[connections[i].start_node] + connections[i].t;
        if (t < time[connections[i].end_node]) time[connections[i].end_node] = t;
    }
    int minflat = flats[0];
    int cur_t = INT.MAXVALUE;

    for (int i = 0; i < flats.size(); i++) {
        int t = time[flats[i]];
        if (t < cur_t) {
            minflat = flats[i];
            cur_t = t;
        }
    }
    return minflat;
}