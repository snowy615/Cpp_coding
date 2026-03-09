#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//pbds = policy based data structure
using namespace std;
using namespace __gnu_pbds;

//key, value = null, comparator = ascending, tree type = red black tree, node update policy = order statistics
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//order statistic tree

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    ordered_set children;
    for (int i = 1; i<=n; i++) children.insert(i);
    int cur_pos = 0;
    for (int rem = n; rem>0; rem--){
        cur_pos = (cur_pos+k)%rem;
        auto it = children.find_by_order(cur_pos);
        cout << *it << " ";
        children.erase(it);
    }
    cout << "\n";
    return 0;
}