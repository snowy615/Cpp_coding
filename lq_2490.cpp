//stack approach
//#include <iostream>
//using namespace std;
//char b[110];
//
//int main(){
//    int n, top = 0;
//    cin >> n;
//    char v;
//    for (int i=1; i<=n; i++){
//        cin >> v;
//        if (v==')' && top > 0 && b[top] == '(') top --;
//        else {
//            top ++;
//            b[top] = v;
//        }
//    }
//    if (top) cout << "No";
//    else cout << "Yes";
//
//}

//number approach
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    char v;
    int cnt = 0;
    bool t = 1;
    for (int i=1; i<=n; i++){
        cin >> v;
        if (v=='(') cnt ++;
        else if (v==')' && cnt > 0) cnt --;
        else t = 0;
    }
    if (t && cnt ==0) cout << "Yes";
    else cout << "No";
}