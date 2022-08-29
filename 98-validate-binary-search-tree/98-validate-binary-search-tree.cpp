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
/*Concept of upper and lower bound
root->left lb can be long_min but ub must be root->val
root->right ub can be long_max but lb must be root->val*/


class Solution {
public:
    bool solve(TreeNode* root,long lb,long ub){
        //base case
        if(root==NULL) return true;
        //check for node's value range
        if(root->val<=lb || root->val>=ub) return false;
        //recursively check for left and right subtree
        return (solve(root->left,lb,root->val) && solve(root->right,root->val,ub));
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,LONG_MIN,LONG_MAX);
    }
};