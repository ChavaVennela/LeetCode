class Trie {
public:
    map<string, int>a;
    Trie() {
        
    }
    
    void insert(string word) {
        a[word]++;
    }
    
    bool search(string word) {
        if(a.find(word)!=a.end()){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        for(auto it=a.begin(); it!=a.end(); it++){
            string s=it->first;
            if(s.substr(0, prefix.size())==prefix){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */