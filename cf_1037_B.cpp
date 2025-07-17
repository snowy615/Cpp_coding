#include <iostream>
using namespace std;
int arr[100010];

int main(){
    int t, n, k;
    int cnt, ls;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> n >> k;
        cnt = 0, ls = 0;
        for (int j=1; j<=n; j++){
            cin >> arr[j];
            if (arr[j] == 1) ls = j;
            else if (j-ls == k){
                cnt ++;
                ls = j+1;
            }

        }
        cout << cnt << "\n";
    }
}