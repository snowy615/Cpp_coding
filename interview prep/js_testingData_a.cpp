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
        if (sample[i] not in pdis) pdis.push_back(sample[i]);
        else pdis[sample[i]] += 1;
    }
    vector<triple> lookup;
    int cur_cnt = 0;
    for (int i = 0; i < pdis.size(); i++) {
        cur_cnt += pdis[i].value();
        lookup.push_back(i, pdis[i].key(), cur_cnt);
    }
    vector<string> final_text(n);
    for (int i = 0; i < sample.size(); i++) {
        cur_num = generate_random_number()*n;
        word = binary_search(lookup, cur_num);
        final_text[i] = word;

    }
    return final_text;
}
