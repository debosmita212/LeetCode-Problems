/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
//DFS Solution
class Solution {
public:
    unordered_map<Node*,Node*> mp; //to check whether a copy already exists or not
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        if(mp.find(node)==mp.end()){ //Not in map
            mp[node]=new Node(node->val,{}); //make copy
            //travel in adjacent and add copy
            for(auto adj:node->neighbors){
                mp[node]->neighbors.push_back(cloneGraph(adj));
            }
        }
        return mp[node];
    }
};