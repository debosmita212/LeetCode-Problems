/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
//Level order traversal 
class Solution {
public:
    void solve(Node* root){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                Node* temp=q.front();
                q.pop();
                //after popping check if size not zero point it's next pointer to the next element of level
                if(size!=0) temp->next=q.front();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return;
    }
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        solve(root);
        return root;
    }
};