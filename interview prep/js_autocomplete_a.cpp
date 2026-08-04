#include <bits/stdc++.h>
using namespace std;
//trie = prefix tree
class Autocomplete {
public:
    Autocomplete(const unordered_map<string, int>& dictionary) {
        //set up the trie structure
    }

    string autocomplete(const string& input) {
        //check if input exists in the trie
        //if no, return empty string
        //if yes, then go through each of the child to find the weight and return the max one
        return "";
    }

    void update(const string& word, int weight) {
        //go through the tree, and add the relevant nodes. At the end of the last character, store the weight.
    }
};
