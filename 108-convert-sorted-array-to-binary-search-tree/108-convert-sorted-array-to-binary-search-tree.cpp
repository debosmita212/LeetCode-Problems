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
/*Approach: as sorted find mid and make that as root
as left and right subtree of bst differs only by one apply that when calling recursive function*/

class Solution {
public:
    TreeNode* solve(int l,int r,vector<int>& nums){
        //base case out of bound
        if(l>r) return NULL;
        int mid=(l+r)/2;
        //make root
        TreeNode* root=new TreeNode(nums[mid]); 
        //left subtree making
        root->left=solve(l,mid-1,nums);
        //right subtree making
        root->right=solve(mid+1,r,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(0,nums.size()-1,nums);
    }
};