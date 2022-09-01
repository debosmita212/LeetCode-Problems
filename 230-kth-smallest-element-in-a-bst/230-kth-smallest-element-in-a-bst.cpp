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
//in BST inorder is sorted
//so when visiting every node increase count when count==k return that node's value
class Solution {
public:
    
    void solve(TreeNode* root,int k,int &count,int &ans){
        if(root==NULL) return;
        solve(root->left,k,count,ans);
        count++;
        if(count==k){
            ans=root->val;
        } 
        solve(root->right,k,count,ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int ans;
        solve(root,k,count,ans);
        return ans;
    }
};