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
private:
    map<TreeNode*,int> subTreeSum;
    int solveSum(TreeNode* root){
        if(root==NULL) return 0;
        else{
            return subTreeSum[root]=root->val+solveSum(root->left)+solveSum(root->right);
        }
    }
    bool isBST(TreeNode* node,int &ans){
        if(!node) return true;
        else if(!node->left && !node->right){
            ans=max(ans,node->val);
            return true;
        }
        else{
            bool left=isBST(node->left,ans);
            bool right=isBST(node->right,ans);
            if(!left || !right) return false;
            else{
                TreeNode* rc=node->right;
                TreeNode* lc=node->left;
                left=false,right=false;
                while(lc && lc->right) lc=lc->right;
                while(rc && rc->left) rc=rc->left;
                if(!lc || lc->val<node->val)
                    left=true;
                if(!rc || rc->val>node->val)
                    right=true;
                if(left && right)
                    ans=max(ans,subTreeSum[node]);
                return left && right;
            }
        }
    }
public:
    
    int maxSumBST(TreeNode* root) {
        solveSum(root);
        int ans=0;
        isBST(root,ans);
        return ans;
    }
};