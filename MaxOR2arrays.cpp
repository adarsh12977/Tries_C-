class Node{
    public:
    Node* links[2];

    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    void putNode(int bit, Node* node){
        links[bit] = node;
    }
    Node* getNode(int bit){
        return links[bit];
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            if(node->containsKey(bit)==false){
                node->putNode(bit,new Node());
            }
            node = node->getNode(bit);
        }
        return;
    }

    int getMax(int num){
        int maxi = 0;
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            if(node->containsKey(!bit)){
                maxi = maxi|(1<<i);
                node = node->getNode(!bit);
            }
            else{
                node = node->getNode(bit);
            }
        }
        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie* trie = new Trie();
        for(int i=0; i<n; i++){
            trie->insert(nums[i]);
        }
        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi,trie->getMax(nums[i]));
        }
        return maxi;
    }
};
