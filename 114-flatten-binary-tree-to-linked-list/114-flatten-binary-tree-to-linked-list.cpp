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
//Morris Traversal-O(N) S.C O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        while(root!=NULL){
            if(root->left!=NULL){
                TreeNode* temp=root->left;
                TreeNode* curr=temp;
                while(curr->right!=NULL)
                    curr=curr->right;
                curr->right=root->right;
                root->left=NULL;
                root->right=temp;
            }
            root=root->right;
        }
    }
};