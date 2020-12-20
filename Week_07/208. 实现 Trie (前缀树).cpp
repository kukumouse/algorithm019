class Trie {
    struct TrieNode{
        map <char,TrieNode*> child_node;
        int end;
        TrieNode():end(0){};
    };
private:
    TrieNode* root;
    bool find(string s,int excat_catch){
        TrieNode* curr = root;
        for (auto a:s){
            if (curr->child_node.count(a) == 0)
                return false;
            curr = curr->child_node[a];
        }

        if (excat_catch)
            return curr->end ? true : false;
        else
            return true;
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for (auto w:word){
            if (curr->child_node.count(w) == 0)
                curr->child_node[w] = new TrieNode();
            curr = curr->child_node[w];
        }
        curr->end = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return find(word,1);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix,0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */