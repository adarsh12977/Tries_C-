class Node{
    
    public:
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    void putNode(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    Node* getNode(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
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
            node = node->getNode(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(node->containsKey(word[i])==false){
                return false;
            }
            node = node->getNode(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(node->containsKey(word[i])==false){
                return false;
            }
            node = node->getNode(word[i]);
        }
        return true;
    }
};
