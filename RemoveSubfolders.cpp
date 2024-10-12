class Node{
    public:
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void addNode(char ch, Node* node){
        links[ch-'a'] = node;
        return;
    }
    Node* getNode(char ch){
        return links[ch-'a'];
    }
    bool isEnd(){
        return flag;
    }
    void setEnd(){
        flag = true;
        return;
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }

    bool insert(string word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(word[i]=='/'){
                continue;
            }
            if(node->containsKey(word[i])==false){
                node->addNode(word[i],new Node());
                node = node->getNode(word[i]);
            }
            else{
                node = node->getNode(word[i]);
                if(node->isEnd()){
                    return false;
                }
            }
        }
        node->setEnd();
        return true;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>ans;
        Trie trie;
        sort(folder.begin(),folder.end());
        for(int i=0; i<folder.size(); i++){
            if(trie.insert(folder[i])){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};
