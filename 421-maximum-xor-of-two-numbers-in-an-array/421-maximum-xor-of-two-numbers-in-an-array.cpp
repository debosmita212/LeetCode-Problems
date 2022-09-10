class Node{
    public:
    Node* links[2];
    bool containsKey(int index){
        return (links[index]!=NULL);
    }
    Node* get(int index){
        return links[index];
    }
    void put(int index,Node* node){
        links[index]=node;
    }
};
class Trie{
    private: Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        //traverse from reverse left to right
        for(int i=31;i>=0;i--){//Storing as bits
            int bit=(num>>i)&1;
            if(!node->containsKey(bit))
                node->put(bit,new Node());
            node=node->get(bit);
        }
    }
    int findMax(int num){
        Node* node=root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            //check if opposite bit contains or not
            if(node->containsKey(!bit)){
                maxi=maxi | (1<<i);
                node=node->get(!bit); //opposite bit
            }
            else{
                node=node->get(bit);
            }
        }
        return maxi;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        //insert all elements 
        for(int i=0;i<nums.size();i++){
            trie.insert(nums[i]);
        }
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,trie.findMax(nums[i]));
        }
        return maxi;
    }
};