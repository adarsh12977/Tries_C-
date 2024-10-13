class Node{
    public:
    Node* links[10];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch-'0']!=NULL;
    }
    void putNode(char ch, Node* node){
        links[ch-'0'] = node;
        return;
    }
    Node* getNode(char ch){
        return links[ch-'0'];
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

    void insert(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->containsKey(word[i])==false){
                node->putNode(word[i],new Node());
            }
            node = node->getNode(word[i]);
        }
    }

    int maxPrefix(string word){
        Node* node = root;
        int cnt = 0;
        for(int i=0; i<word.length(); i++){
            if(node->containsKey(word[i])){
                cnt++;
                node = node->getNode(word[i]);
            }
            else{
                return cnt;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        Trie* trie = new Trie();
        trie->insert(to_string(arr1[0]));
        for(int i=1; i<n; i++){
            trie->insert(to_string(arr1[i]));
        }
        int maxi = 0;
        for(int i=0; i<m; i++){
            maxi = max(maxi,trie->maxPrefix(to_string(arr2[i])));
        }
        return maxi;
    }
};
