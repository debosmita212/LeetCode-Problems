/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root==NULL) return NULL;
        //both values are less than root go to left subtree
        if(p->val<root->val && q->val<root->val) 
            return lowestCommonAncestor(root->left,p,q);
        //both values are more than root go to right subtree
        if(p->val>root->val && q->val>root->val)
            return lowestCommonAncestor(root->right,p,q);
        //both values lying in opposite subtrees so lca is root
        return root;
    }
};