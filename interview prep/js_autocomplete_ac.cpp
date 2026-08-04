#include <bits/stdc++.h>
using namespace std;


struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int max_weight;
    string best_word; //cache best word and weight at every node

    TrieNode() {
        max_weight = -1;
        best_word = "";
    }
};
class Autocomplete {
private:
    TrieNode* root;

public:
    Autocomplete(const unordered_map<string, int>& dictionary) {
        root = new TrieNode();

        for (const auto& pair: dictionary) {
            update(pair.first, pair.second);
        }
    }

    string autocomplete(const string& input) {
        TrieNode* cur = root;
        for (char c: input) {
            if (cur->children.find(c) == cur->children.end()) return "";
            cur = cur->children[c];
        }
        return cur->best_word;
    }

    void update(const string& word, int weight) {
        TrieNode* cur = root;
        for (char c: word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }

            cur = cur->children[c];

            if (weight > cur->max_weight) {
                cur->max_weight = weight;
                cur->best_word = word;
            }
        }
    }
};
