#include <bits/stdc++.h>
using namespace std;

struct triple {
    int id;
    string word;
    int ccnt;
};

vector<string> generate_text(const vector<string>& sample, int n) {
    map<string, int> pdis;
    for (int i = 0; i < sample.size(); i++) {
        pdis[sample[i]] ++; //initialization automatically handled
    }

    vector<triple> lookup;
    int cur_cnt = 0;
    int id = 0;

    for (const auto& pair: pdis) {
        lookup.push_back({id++, pair.first, cur_cnt});
    }

    vector<string> final_text(n);
    int total_words = sample.size();

    for (int i = 0; i < n; i++) {
        int cur_num = rand() % total_words;
        int left = 0;
        int right = lookup.size() - 1;
        string selected_word = "";

        while (left <= right) {
            int mid = left + (right-left)/2;
            if (cur_num < lookup[mid].ccnt) {
                selected_word = lookup[mid].word;
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        final_text[i] = selected_word;
    }
    return final_text;
}