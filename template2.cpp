class Node{
    
    public:
    Node* links[26];
    int cntEndsWith = 0;
    int cntPrefix = 0;
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    void putNode(char ch, Node* node){
        links[ch-'a'] = node;
        return;
    }
    
    Node* getNode(char ch){
        return links[ch-'a'];
    }
    
    void increaseEnd(){
        cntEndsWith++;
        return;
    }
    
    void increasePrefix(){
        cntPrefix++;
        return;
    }
    
    void deleteEnd(){
        cntEndsWith--;
        return;
    }
    
    void deletePrefix(){
        cntPrefix--;
        return;
    }
    
};

class Trie{
    
    public:
    Node* root;
    Trie(){
        root = new Node();
    }
    
    void insert(string word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(node->containsKey(word[i])==false){
                node->putNode(word[i], new Node());
            }
            node->getNode(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    
    int countWords(string word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(node->containsKey(word[i])==false){
                return 0;
            }
            node->getNode(word[i]);
        }
        return node->cntEndsWith;
    }
    
    int cntStartsWith(string word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(node->containsKey(word[i])==false){
                return 0;
            }
            node->getNode(word[i]);
        }
        return node->cntPrefix;
    }
    
    void erase(string word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            node->getNode(word[i]);
            node->deletePrefix();
        }
        node->deleteEnd();
        return;
    }
    
};
