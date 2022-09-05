/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/*Simple level order traversal*/
/*here children array is there instead of left and right child so use another loop to iterate over
that vector and push those child into queue*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                Node* node=q.front();
                q.pop();
                temp.push_back(node->val);
                int k=0;
                while(k<node->children.size()){
                    q.push(node->children[k++]);
                }
                
            }
            ans.push_back(temp);
        }
        return ans;
    }
};