class WordDictionary {
public:
    int sz;
    vector<vector<int>> ch;
    vector<int> val;
    
    /** Initialize your data structure here. */
    WordDictionary() {
        sz = 1;
        ch.resize(1);
        ch[0].resize(26);
        val.resize(1);
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int u = 0;
        for (auto& c: word){
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
    
    
    bool dfs(int u, string word){
        for (int i = 0; i < word.length(); i++){
            if (word[i] == '.'){
                for (int j = 0; j < 26; j++)
                    if (ch[u][j] and dfs(ch[u][j], word.substr(i+1))) 
                        return true;
                return false;
            }
            else {
                int j = word[i] - 'a';
                if (!ch[u][j]) return false;
                u = ch[u][j];
            }
        }
        return val[u];
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(0, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */