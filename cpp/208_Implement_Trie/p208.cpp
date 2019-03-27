#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    int sz;
    vector<vector<int>> ch;
    vector<int> val;
    /** Initialize your data structure here. */
    Trie() {
        sz = 1; ch.resize(1); val.resize(1);
        ch[0].resize(26);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int u = 0;
        for (auto& c: word) {
            int j = c - 'a';
            if (!ch[u][j]){
                ch.push_back(vector<int>(26,0));
                ch[u][j] = sz;
                val.push_back(0);
                sz++;
            }
            u = ch[u][j];
        }
        val[u] = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int u = 0;
        for (auto&c : word){
            int j = c - 'a';
            if (!ch[u][j]) return false;
            u = ch[u][j];
        }
        return val[u];
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool dfs(int u) {
        if (val[u]) return true;
        for (int i = 0; i < 26; i++)
            if (ch[u][i] and dfs(ch[u][i])) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        int u = 0;
        for (auto& c : prefix){
            int j = c - 'a';
            if (!ch[u][j]) return false;
            u = ch[u][j];
        }
        
        return dfs(u);
    }
};

int main() {
    Trie* obj = new Trie();
    string word = "abcd";
    string prefix = "ab";
    obj->insert(word);
    cout << obj->search("bcd") << endl;

    cout << obj->startsWith(prefix) << endl;
    // cout << param_2 << " " << param_3 << endl;
    return 0;
}