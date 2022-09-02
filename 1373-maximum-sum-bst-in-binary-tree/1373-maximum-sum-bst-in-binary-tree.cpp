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
class NodeValue{
  public:
    int maxNode,minNode,maxSum;
    NodeValue(int minNode,int maxNode,int maxSum){
        this->minNode=minNode;
        this->maxNode=maxNode;
        this->maxSum=maxSum;
    }
};
class Solution {
    //same as largest bst in binary postorder
    int res=INT_MIN;
    NodeValue solve(TreeNode* root){
        if(root==NULL) return NodeValue(INT_MAX,INT_MIN,0);
        
        auto left=solve(root->left);
        auto right=solve(root->right);
        
        if(left.maxNode<root->val && root->val<right.minNode){
            //valid bst
            res=max(res,left.maxSum+right.maxSum+root->val);
            return NodeValue(min(root->val,left.minNode),
                             max(root->val,right.maxNode),left.maxSum+right.maxSum
                            +root->val);
        }
        //Not a BST
        return NodeValue(INT_MIN,INT_MAX,max(left.maxSum,right.maxSum));
    }
public:
    int maxSumBST(TreeNode* root) {
        solve(root);
        if(res<0) return 0;
        return res;
    }
};