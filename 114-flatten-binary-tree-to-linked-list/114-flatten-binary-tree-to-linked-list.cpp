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
//Iterative solution using stack-O(N) s.c O(n)
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            //pop the top
            TreeNode* temp=st.top();
            st.pop();
            //push it's right child and left child if exists
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
            //attach the top to temp right
            if(!st.empty())
                temp->right=st.top();
            temp->left=NULL;
        }
    }
};