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
//Condition for balanced binary tree abs(lh-rh)<=1
//Instead of checking heights for every node, we can just modify the height function to reduce the time to O(n)
class Solution {
public:
    int check(TreeNode* root){
        if(root==NULL) return 0;
        int lh=check(root->left);
        if(lh==-1) return -1;
        int rh=check(root->right);
        if(rh==-1) return -1;
        //balanced binary tree checking
        if(abs(lh-rh)>1) return -1;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) { 
        //if returns -1 then not height balanced
        return check(root)!=-1;
    }
};