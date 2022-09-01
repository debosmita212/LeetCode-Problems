/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator{
    stack<TreeNode*> st;
    bool reverse=true;
    //reverse->true= before
    //reverse->false= next
    public:
    BSTIterator(TreeNode* root,bool isReverse){
        reverse=isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return !st.empty();
    }
    //returns the smallest number
    int next(){
        TreeNode* temp=st.top();
        st.pop();
        
        if(!reverse)
            pushAll(temp->right);
        else
            pushAll(temp->left);
        return temp->val;
    }
    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
    
            if(reverse)
                node=node->right;
            else
                node=node->left;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        BSTIterator l(root,false); //next will start from smallest
        BSTIterator r(root,true); //next will start from largest
        
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};