#include <iostream>
#include <algorithm>

using namespace std;

// Structure to represent a rectangle
struct Rect {
    long long x1, y1, x2, y2;

    // Function to calculate the area of the rectangle
    long long area() const {
        if (x1 >= x2 || y1 >= y2) return 0; // Invalid or degenerate rectangle
        return (x2 - x1) * (y2 - y1);
    }
};

// Function to find the overlapping rectangle between two rectangles
Rect intersect(const Rect& a, const Rect& b) {
    Rect res;
    res.x1 = max(a.x1, b.x1);
    res.y1 = max(a.y1, b.y1);
    res.x2 = min(a.x2, b.x2);
    res.y2 = min(a.y2, b.y2);

    // If the boundaries don't form a valid rectangle, set area to 0
    if (res.x1 >= res.x2 || res.y1 >= res.y2) {
        res.x1 = res.y1 = res.x2 = res.y2 = 0;
    }
    return res;
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Rect w, b1, b2;

    // Read coordinates
    if (!(cin >> w.x1 >> w.y1 >> w.x2 >> w.y2)) return 0;
    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;

    // 1. Total area of the white sheet
    long long area_w = w.area();

    // 2. Area covered by each black sheet individually
    long long cover1 = intersect(w, b1).area();
    long long cover2 = intersect(w, b2).area();

    // 3. Area covered by both black sheets simultaneously (Overlap)
    long long overlap = intersect(intersect(w, b1), b2).area();

    // Calculate the total unique covered area using inclusion-exclusion
    long long total_covered = cover1 + cover2 - overlap;

    // 4. Determine visibility
    if (total_covered == area_w) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

    return 0;
}