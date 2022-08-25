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
//Iterative solution-> left-right-root
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st1,st2;
        TreeNode* node=root;
        //push node into stack
        st1.push(root);
        while(!st1.empty()){
             //pop the top of s1 and push it to s2
            node=st1.top();
            st1.pop();
            st2.push(node);
            //if the popped node's left exists push it to s1
            if(node->left){
                st1.push(node->left);
            }
            //if the popped node's right exists push it to s1
            if(node->right){
                st1.push(node->right);
            }
        }
        //Popping the elements and printing it LIFO
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};