//The Fenwick Tree (Binary Indexed Tree), relative fast update and query

/*
 Fenwick Tree (Binary Indexed Tree):
 1. The Goal of the TreeStandard arrays are fast at updating but slow at calculating sums.Prefix-sum arrays are fast at calculating sums but slow at updating.The Fenwick Tree is the perfect middle ground: it makes both updating a value and calculating a sum incredibly fast (in $O(\log N)$ time).
 2. The "Chunk" SystemInstead of storing just one number, or a sum of all previous numbers, each index in a Fenwick Tree stores a "chunk" of numbers.These chunks are always sizes of powers of 2 (1, 2, 4, 8, 16...).
 3. The Binary SecretThe size of the chunk an index is responsible for is hidden in its binary number.The Rule: Look at the index in binary. The value of the rightmost 1 bit tells you the exact chunk size.Example: Index 6 is 0110. The rightmost 1 is in the "2s" column. So, Index 6 holds a chunk of 2 items.
 4. The Magic Math (i & -i)The code i & -i is just a fast bitwise trick that calculates that rightmost 1 bit for you. It literally means "get the chunk size."
 5. How We Use It to "Hop"To Query (Find a sum): You start at your index, grab its chunk, and subtract the chunk size to hop backward to the next piece of the puzzle until you hit 0.To Update (Change a value): You update your index, and then add the chunk size to hop forward to update all the larger chunks that include your number, until you hit the maximum size of the array.
 */

/*
#include <bits/stdc++.h>
using namespace std;

struct Range{
    int l, r, id;
};

bool cmp(const Range& a, const Range& b){
    if (a.l != b.l) return a.l < b.l;
    return a.r > b.r;
}

struct fenwickTree {
    int n;
    vector<int> tree;
    fenwickTree(int n): n(n), tree(n+1, 0) {}

    void add(int i, int delta) {
        for (; i <= n; i += i & -i) {//least significant bit(LSB)
            tree[i] += delta;
        }
    }

    int query(int i){
        int sum = 0;
        for (; i>0; i -= i&-i) sum += tree[i];
        return sum;
    }

};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Range> ranges(n);
    vector<int>y_coords;

    for (int i=0; i<n; i++){
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].id = i;
        y_coords.push_back(ranges[i].r);
    }

    sort(y_coords.begin(), y_coords.end());
    y_coords.erase(unique(y_coords.begin(), y_coords.end()), y_coords.end());
    int max_y_rank = y_coords.size();

    sort(ranges.begin(), ranges.end(), cmp);

    vector<int> contains(n);
    vector<int> contained_by(n);

    fenwickTree bit_contains(max_y_rank);
    for (int i = n-1; i >= 0; i--){
        int y_rank = lower_bound(y_coords.begin(), y_coords.end(), ranges[i].r)-y_coords.begin()+1;
        contains[ranges[i].id] = bit_contains.query(y_rank);
        bit_contains.add(y_rank, 1);
    }
    fenwickTree bit_contained_by(max_y_rank);
    for (int i = 0; i<n; i++) {
        int y_rank = lower_bound(y_coords.begin(), y_coords.end(), ranges[i].r)-y_coords.begin()+1;
        contained_by[ranges[i].id] = bit_contained_by.query(max_y_rank) - bit_contained_by.query(y_rank-1);
        bit_contained_by.add(y_rank, 1);
    }

    for (int i = 0; i < n; i++) cout << contains[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; i++) cout << contained_by[i] << " ";
    cout << "\n";

    return 0;
}
*/

// The Fenwick Tree (Binary Indexed Tree), relative fast update and query

/*
 Fenwick Tree (Binary Indexed Tree):
 1. The Goal of the Tree: Standard arrays are fast at updating but slow at calculating sums. Prefix-sum arrays are fast at calculating sums but slow at updating. The Fenwick Tree is the perfect middle ground: it makes both updating a value and calculating a sum incredibly fast (in O(log N) time).
 2. The "Chunk" System: Instead of storing just one number, or a sum of all previous numbers, each index in a Fenwick Tree stores a "chunk" of numbers. These chunks are always sizes of powers of 2 (1, 2, 4, 8, 16...).
 3. The Binary Secret: The size of the chunk an index is responsible for is hidden in its binary number. The Rule: Look at the index in binary. The value of the rightmost 1 bit tells you the exact chunk size. Example: Index 6 is 0110. The rightmost 1 is in the "2s" column. So, Index 6 holds a chunk of 2 items.
 4. The Magic Math (i & -i): The code i & -i is just a fast bitwise trick that calculates that rightmost 1 bit for you. It literally means "get the chunk size."
 5. How We Use It to "Hop": To Query (Find a sum): You start at your index, grab its chunk, and subtract the chunk size to hop backward to the next piece of the puzzle until you hit 0. To Update (Change a value): You update your index, and then add the chunk size to hop forward to update all the larger chunks that include your number, until you hit the maximum size of the array.
 */

#include <bits/stdc++.h> // Includes all standard C++ libraries
using namespace std;     // Allows us to use standard functions without typing "std::" every time

// Structure to hold all the data for a single range
struct Range{
    int l;  // Left endpoint
    int r;  // Right endpoint
    int id; // Original index from the input (so we can print answers in the right order)
};

// Custom sorting rule for our ranges
bool cmp(const Range& a, const Range& b){
    if (a.l != b.l) return a.l < b.l; // Primary rule: Sort by left endpoint in Ascending order
    return a.r > b.r;                 // Tie-breaker: If lefts are equal, sort by right endpoint in Descending order
}

// Our custom data structure for fast updates and range queries
struct fenwickTree {
    int n;             // Maximum size of the tree
    vector<int> tree;  // The array that actually holds our "chunks"

    // Constructor: Initializes n and creates a vector of size n+1 filled with 0s
    // (Size is n+1 because Fenwick Trees MUST be 1-indexed)
    fenwickTree(int n): n(n), tree(n+1, 0) {}

    // Adds a value (delta) to a specific index (i)
    void add(int i, int delta) {
        // Start at 'i', and keep adding the LSB to hop forward to update all larger chunks
        for (; i <= n; i += i & -i) {
            tree[i] += delta;
        }
    }

    // Calculates the sum of everything from index 1 up to index (i)
    int query(int i){
        int sum = 0;
        // Start at 'i', and keep subtracting the LSB to hop backward and collect all pieces of the sum
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};

int main(){
    // Optimizes C++ standard I/O operations to make reading/writing super fast
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n; // Read the total number of ranges

    vector<Range> ranges(n); // Array to hold our range objects
    vector<int> y_coords;    // Array just to hold all the right endpoints (y-values) for compression

    // Loop through input and populate our arrays
    for (int i = 0; i < n; i++){
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].id = i;                // Save the original input order (0, 1, 2...)
        y_coords.push_back(ranges[i].r); // Store the right endpoint for later
    }

    // --- COORDINATE COMPRESSION ---
    // Right endpoints can be up to 1,000,000,000, which is too big for an array index.
    // This process shrinks them down to ranks (1, 2, 3...)
    sort(y_coords.begin(), y_coords.end()); // 1. Sort all the y-coordinates
    // 2. Remove all duplicates so every unique y-value has a unique rank
    y_coords.erase(unique(y_coords.begin(), y_coords.end()), y_coords.end());
    int max_y_rank = y_coords.size(); // The highest rank we will need for our tree

    // Sort the actual ranges using our custom cmp function (Left ascending, Right descending)
    sort(ranges.begin(), ranges.end(), cmp);

    // Arrays to store our final answers. Using size 'n' initializes them with zeros.
    vector<int> contains(n);
    vector<int> contained_by(n);

    // --- 1. CALCULATE HOW MANY OTHER RANGES IT CONTAINS ---
    fenwickTree bit_contains(max_y_rank); // Create a fresh tree
    // Loop backwards (Right to Left).
    // Because we go backwards, any range we process is guaranteed to have a larger or equal left endpoint.
    for (int i = n - 1; i >= 0; i--){
        // Find the compressed rank (1-based index) of our current right endpoint
        int y_rank = lower_bound(y_coords.begin(), y_coords.end(), ranges[i].r) - y_coords.begin() + 1;

        // Ask the tree: "How many processed ranges have a right endpoint <= my y_rank?"
        // Save the answer to the range's original ID slot
        contains[ranges[i].id] = bit_contains.query(y_rank);

        // Add ourselves to the tree so the next ranges moving leftwards can "see" us
        bit_contains.add(y_rank, 1);
    }

    // --- 2. CALCULATE HOW MANY OTHER RANGES IT IS CONTAINED BY ---
    fenwickTree bit_contained_by(max_y_rank); // Create another fresh tree
    // Loop forwards (Left to Right).
    // Because we go forwards, any range we process is guaranteed to have a smaller or equal left endpoint.
    for (int i = 0; i < n; i++) {
        // Find the compressed rank (1-based index) of our current right endpoint
        int y_rank = lower_bound(y_coords.begin(), y_coords.end(), ranges[i].r) - y_coords.begin() + 1;

        // Ask the tree: "How many processed ranges have a right endpoint >= my y_rank?"
        // To do this, we take the TOTAL ranges seen (query(max_y_rank)) and subtract the ones that are too small (query(y_rank - 1))
        contained_by[ranges[i].id] = bit_contained_by.query(max_y_rank) - bit_contained_by.query(y_rank - 1);

        // Add ourselves to the tree so the next ranges moving rightwards can "see" us
        bit_contained_by.add(y_rank, 1);
    }

    // --- OUTPUT ---
    // Print the 'contains' results in the original input order
    for (int i = 0; i < n; i++) cout << contains[i] << " ";
    cout << "\n";
    // Print the 'contained_by' results in the original input order
    for (int i = 0; i < n; i++) cout << contained_by[i] << " ";
    cout << "\n";

    return 0; // End program successfully
}