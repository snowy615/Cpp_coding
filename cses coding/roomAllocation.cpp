#include <bits/stdc++.h>
using namespace std;

struct Customer {
    int arrival, departure, id;

    // Sort primarily by arrival, secondarily by departure
    bool operator<(const Customer& other) const {
        if (arrival != other.arrival) return arrival < other.arrival;
        return departure < other.departure;
    }
};

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Customer> customers(n);
    for (int i = 0; i < n; i++) {
        cin >> customers[i].arrival >> customers[i].departure;
        customers[i].id = i;
    }

    // Sort customers by arrival time
    sort(customers.begin(), customers.end());

    // pq stores {departure_day, room_number}
    // We use greater<> to make it a min-heap (earliest departure at top)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> room_assigned(n);
    int rooms_count = 0;

    for (int i = 0; i < n; i++) {
        // If the earliest vacant room is free BEFORE the current arrival
        if (!pq.empty() && pq.top().first < customers[i].arrival) {
            // Reuse the room
            int room_num = pq.top().second;
            pq.pop();
            pq.push({customers[i].departure, room_num});
            room_assigned[customers[i].id] = room_num;
        } else {
            // Need a brand new room
            rooms_count++;
            pq.push({customers[i].departure, rooms_count});
            room_assigned[customers[i].id] = rooms_count;
        }
    }

    // Output results
    cout << rooms_count << "\n";
    for (int i = 0; i < n; i++) {
        cout << room_assigned[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}