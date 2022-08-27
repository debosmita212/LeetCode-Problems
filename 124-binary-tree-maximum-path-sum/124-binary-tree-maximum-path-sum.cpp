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
//Formula for maxpathsum through a given node suppose it is root
        //value+leftSum+rightSum
        //apply it for every node
class Solution {
public:
    int solve(TreeNode* root,int &maxi){
        //base case
        if(root==NULL) return 0;
        //calculate the leftsum for a curving point
        //if leftSum returns negative sum ignore it with 0 as negative value will not be able to increase maxPathSum same goes for rightSum
        int l=max(0,solve(root->left,maxi));
        int r=max(0,solve(root->right,maxi));
        maxi=max(maxi,l+r+root->val);
        //return the value which the node will return to its parent not the maxPathSum
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
       int maxi=INT_MIN;
        solve(root,maxi);
        return maxi;
    }
};