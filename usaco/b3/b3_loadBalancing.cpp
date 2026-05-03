#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

bool compareY(const Point& p1, const Point& p2){
    return p1.y < p2.y;
}

int main(){
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Point> cows(n);
    vector<int> x;
    for (int i = 0; i<n; i++){
        cin >> cows[i].x >> cows[i].y;
        x.push_back(cows[i].x);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    sort(cows.begin(), cows.end(), compareY);

    int mcows = n;
    for (int i = 0; i < x.size(); i++){
        int a = x[i] + 1; //vertical fence
        //a = above, b=below, l = left, r=right
        int al = 0, ar = 0, bl = 0, br = 0;

        for (int k = 0; k < n; k++){ //horizontal fence at bottom
            if (cows[k].x < a) al++;
            else ar ++;
        }

        for (int j = 0; j < n; j++){ //move horiztonal fence
            if (cows[j].x < a){
                al --;
                bl ++;
            } else {
                ar --;
                br++;
            }

            if (j == n-1 || cows[j].y != cows[j+1].y){ //check safe
                int cur_max = max({al, ar, bl, br});
                if (cur_max < mcows) mcows = cur_max;
            }
        }
    }
    cout << mcows;
    return 0;
}

//slow
//#include <bits/stdc++.h>
//using namespace std;
//
//struct Point {
//    int x, y;
//};
//
//int main(){
//    freopen("balancing.in", "r", stdin);
//    freopen("balancing.out", "w", stdout);
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    int n;
//    cin >> n;
//
//    vector<Point> cows(n);
//    vector<int> x, y;
//    for (int i = 0; i<n; i++){
//        cin >> cows[i].x >> cows[i].y;
//        x.push_back(cows[i].x);
//        y.push_back(cows[i].y);
//    }
//    sort(x.begin(), x.end());
//    sort(y.begin(), y.end());
//    x.erase(unique(x.begin(), x.end()), x.end());
//    y.erase(unique(y.begin(), y.end()), y.end());
//
//    int mcows = n;
//    for (int i = 0; i < x.size(); i++){
//        int a = x[i] + 1;
//        for (int j = 0; j < y.size(); j++){
//            int b = y[j]+1;
//            int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
//            for (int k = 0; k < n; k++){
//                if (cows[k].x > a && cows[k].y > b) q1 ++;
//                else if (cows[k].x < a && cows[k].y > b) q2 ++;
//                else if (cows[k].x < a && cows[k].y < b) q3 ++;
//                else q4 ++;
//            }
//            int cur_max = max({q1, q2, q3, q4});
//            if (cur_max < mcows) mcows = cur_max;
//        }
//    }
//    cout << mcows;
//    return 0;
//}