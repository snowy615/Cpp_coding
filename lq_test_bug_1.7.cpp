#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Correct solution (passes all cases)
int correct_solution(const string& s, int l, int r) {
    int count = 0;
    for (int i = l-1; i < r-1; i++) {
        if (s[i] == '1' && s[i+1] == '0') count++;
    }
    return count;
}

// Your solution (fails 1/10 cases)
int your_solution(const string& a, int l, int r) {
    int n = a.size();
    int s[200005] = {0};
    for (int i = 1; i <= n; i++) {
        s[i] = s[i-1];
        if (i < n && (a[i-1] == '1' && a[i] == '0')) s[i]++;
    }
    int res = s[r] - s[l-1];
    if (r < n && (a[r-1] == '1' && a[r] == '0')) res--;
    return res;
}

int main() {
    srand(time(0));

    for (int test_num = 1; test_num <= 1000; test_num++) {
        int n = rand() % 1000 + 1;  // Random n between 1-1000
        string s;
        for (int i = 0; i < n; i++) {
            s += (rand() % 2) ? '1':'0';  // Random binary string
        }

        int m = rand() % 100 + 1;  // Random number of queries

        vector<pair<int, int>> queries;
        for (int i = 0; i < m; i++) {
            int l = rand() % n + 1;
            int r = rand() % (n - l + 1) + l + 1;
            if (r > n) r = n + 1;
            queries.emplace_back(l, r);
        }

        bool failed = false;
        for (auto [l, r]:queries) {
            int correct = correct_solution(s, l, r);
            int yours = your_solution(s, l, r);

            if (correct != yours) {
                cout << "Test Case #" << test_num << " FAILED!\n";
                cout << "String: " << s << "\n";
                cout << "Query: [" << l << ", " << r << ")\n";
                cout << "Correct answer: " << correct << "\n";
                cout << "Your answer: " << yours << "\n\n";
                failed = true;
                break;
            }
        }

        if (failed) {
            // Print the failing test case for debugging
            cout << "Failing test case details:\n";
            cout << n << "\n" << s << "\n" << m << "\n";
            for (auto [l, r]:queries) {
                cout << l << " " << r << "\n";
            }
            break;
        }
    }

    return 0;
}