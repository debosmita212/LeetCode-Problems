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
/*Concept->Upperbound
for left subtree upperbound will be root->val and for right subtree 
upperbound will be INT_MAX*/

class Solution {
public:
    TreeNode* solve(int &i,int ub,vector<int>& preorder){
        //base case -> reaches last index or element exceeds upper bound
        if(i==preorder.size() || preorder[i]>ub) return NULL;
        //make root 
        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=solve(i,root->val,preorder);
        root->right=solve(i,ub,preorder);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(i,INT_MAX,preorder);
    }
};