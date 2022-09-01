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
    void solve(TreeNode* root,int maxi,int &count){
        if(root==NULL) return;
        //if node->val is greater than equal to maxi then increase count
        //and update maxi
        if(root->val>=maxi){
            count++;
            maxi=root->val;
        } 
        //traverse left
        solve(root->left,maxi,count);
        //traverse right
        solve(root->right,maxi,count);
        
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        
        int count=0;
        solve(root,INT_MIN,count);
        return count;
    }
};