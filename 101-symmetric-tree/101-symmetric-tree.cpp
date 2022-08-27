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
class Solution {
public:
    //base case if both null then symmetrical
        //since mirror follows left->right and right<-left
        //so we are checking when we are going to traverse left for left subtree and right for right subtree both are the same or not
    bool solve(TreeNode* node1,TreeNode* node2){
        if(node1==NULL || node2==NULL)
            return node1==node2;
        if(node1->val!=node2->val) return false;
        return (solve(node1->left,node2->right)
            && solve(node1->right,node2->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        //left child and right child become roots for left and right subtrees respectively
        return solve(root->left,root->right);
    }
};