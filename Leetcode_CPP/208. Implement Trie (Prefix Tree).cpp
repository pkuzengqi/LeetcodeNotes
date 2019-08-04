class Node{
public:
    Node *next[26];
    bool end;
    Node(){
        memset(next, NULL, sizeof(next));
        end=false;
    }
    ~Node(){}
};


class Trie {
public:
    Node *root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *p=root;
        for(int i=0, j=0;i<word.length();++i){
            j=word[i]-'a';
            if(p->next[j]==NULL)
                p->next[j]=new Node();
            p=p->next[j];
        }
        p->end=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto p=root;
        for(int i=0, j=0;i<word.length();++i){
            j=word[i]-'a';
            if(p->next[j]==NULL)
                return false;
            p=p->next[j];
        }
        return p->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto p=root;
        for(int i=0, j=0;i<prefix.length();++i){
            j=prefix[i]-'a';
            if(p->next[j]==NULL)
                return false;
            p=p->next[j];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */