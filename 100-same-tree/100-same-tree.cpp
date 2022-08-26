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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //base case-> if anyone becomes Null then check both nodes are same or not
        if(p==NULL || q==NULL)
            return p==q;
        //traverse recursively for left and right and if their value is same then return true
        return (isSameTree(p->left,q->left)&& isSameTree(p->right,q->right)
               && p->val==q->val);
    }
};