//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//using ll = long long;
//
//int chocoDate[100010];
//struct T{
//    ll p, d, q;
//};
//
//bool comparePDQ(const T &a, const T &b) {
//    if (a.p != b.p) return a.p < b.p;
//    if (a.d != b.d) return a.d < b.d;
//    return a.q < b.q;
//}
//
//vector<T> v;
//ll x, n;
//
//int main(){
//    cin >> x;
//    cin >> n;
//    ll p, d, q;
//    for (int i=1; i<=n; i++){
//        cin >> p >> d >> q;
//        v.push_back({p, d, q});
//    }
//    sort(v.begin(), v.end(), comparePDQ);
//    ll q_c = 0, p_c = 0;
//    for (auto vv: v){
//        if (q_c == x) break;
//        ll mq = min(min(vv.q, vv.d), x-q_c);
//        ll qq = 0;
//        for (int l=vv.d; l>=1; l--){
//            if(!chocoDate[l]) {
//                chocoDate[l] = 1;
//                qq ++;
//            }
//            if (qq == mq) break;
//        }
//        p_c += qq*vv.p;
//        q_c += qq;
//    }
//    if (q_c == x) cout << p_c;
//    else cout << "-1";
//    return 0;
//
//}

//DSU approach = path compression
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int MAXD = 100010;
int parent[MAXD];

int find(int d) {
    if (parent[d] == d) return d;
    return parent[d] = find(parent[d]);
}

void unite(int d) {
    parent[d] = find(d - 1);
}

struct Task {
    ll price, deadline, quantity;
};

bool compare(const Task &a, const Task &b) {
    if (a.price != b.price) return a.price < b.price;
    if (a.deadline != b.deadline) return a.deadline < b.deadline;
    return a.quantity < b.quantity;
}

int main() {
    ll x, n;
    cin >> x >> n;

    vector<Task> tasks(n);
    for (int i = 0; i < n; ++i)
        cin >> tasks[i].price >> tasks[i].deadline >> tasks[i].quantity;

    sort(tasks.begin(), tasks.end(), compare);

    // Initialize DSU parent array
    for (int i = 0; i < MAXD; ++i) parent[i] = i;

    ll totalQ = 0, totalCost = 0;
    for (const auto &t : tasks) {
        for (ll i = 0; i < t.quantity && totalQ < x; ++i) {
            int available = find(t.deadline);
            if (available == 0) break; // no available days
            unite(available); // mark this day as used
            totalCost += t.price;
            ++totalQ;
        }
        if (totalQ == x) break;
    }

    cout << (totalQ == x ? totalCost : -1) << endl;
    return 0;
}
