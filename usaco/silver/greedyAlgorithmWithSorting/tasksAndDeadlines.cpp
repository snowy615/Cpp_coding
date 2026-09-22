#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Task{
    ll duration;
    ll deadline;
};

bool compareTasks(const Task& a, const Task& b){
    return a.duration < b.duration;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Task> tasks(n);
    for (int i = 0; i<n; i++){
        cin >> tasks[i].duration >> tasks[i].deadline;
    }

    sort(tasks.begin(), tasks.end(), compareTasks);

    ll cur_time = 0;
    ll max_reward = 0;

    for (int i = 0; i<n; i++){
        cur_time += tasks[i].duration;
        max_reward += (tasks[i].deadline - cur_time);
    }

    cout << max_reward;
    return 0;
}