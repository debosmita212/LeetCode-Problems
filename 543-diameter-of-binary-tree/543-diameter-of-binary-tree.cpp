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
//at any curving point diameter=height of left subtree+height of right subtree
//to reduce time complexity we will just modify the height function and there pass diameter as a
//reference and update it -> T.C=O(n) S.C=O(n)
class Solution {
public:
    int findHeight(TreeNode* root,int &diameter){
        if(root==NULL) return 0;
        int lh=findHeight(root->left,diameter); //left subtree height
        int rh=findHeight(root->right,diameter); //right subtree height
        diameter=max(diameter,lh+rh);//diameter updation
        return 1+max(lh,rh); //return max height
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int diameter=0;
        findHeight(root,diameter);
        return diameter;
    }
};