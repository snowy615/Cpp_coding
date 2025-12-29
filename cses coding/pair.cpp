#include <utility>

std::pair<int, int> p;

p.first = 10;
p.second = 20;

// Accessing
cout << p.first << " " << p.second; // Output: 10 20

// 1. Constructor
pair<int, int> p1(5, 7);

// 2. make_pair function (Older style, but still common)
pair<int, int> p2 = make_pair(5, 7);

// 3. Curly Braces (Cleanest)
pair<int, int> p3 = {5, 7};