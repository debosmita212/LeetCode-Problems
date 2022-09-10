class Node{
    public:
    Node* links[26];
    bool flag=false;//denote the end
    bool containsKey(char ch){
        return links[ch-'a']!=NULL; //means if contains key returns true else false
    }
    //create reference trie
    void put(char ch,Node* node){
        links[ch-'a']=node; //in a new node put the character
    }
    //to get next node for traversal
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true; //at the end of word set the flag true
    }
    bool isEnd(){
        return flag;  //checking if the word is completed or not
    }
};
class Trie {
    private: Node* root;
public:
    Trie() {
        root=new Node(); //create new object
    }
    //T.C=O(wordlength)
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    //T.C=O(wordlength)
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])) return false;
            node=node->get(word[i]);
        }
        return node->isEnd();
    }
    //T.C=O(prefixlength)
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containsKey(prefix[i])) return false;
            node=node->get(prefix[i]);
        }
        return true; //checks only prefix so do not need to check for flag for whole word
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */