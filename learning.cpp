//policy based set

include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
indexed_set s;
s.insert(2);
auto x = s.find_by_order(2); // find by order = get iterator to the element at index 2 in a sorted set
cout << *x << "\n";
cout << s.order_of_key(7); // order of key = get index of element 7, if element does not appear, return the place it would have been in the set
