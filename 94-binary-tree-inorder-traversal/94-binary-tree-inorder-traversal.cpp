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
//Morris Traversal ->Left-Root-Right
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;
        //until curr becomes null traverse
        while(curr!=NULL){
            //if curr->left is null then push the curr val and goes to curr->right
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                //curr not null
                TreeNode* temp=curr->left;
                //goes to the rightmost element in left subtree
                while(temp->right && temp->right!=curr){
                    temp=temp->right;
                }
                //check if it is null then link it with curr and points curr to curr->left
                if(temp->right==NULL){
                    temp->right=curr;
                    curr=curr->left;
                }
                else{
                    //if it is already points to curr break the link
                    //push the curr->val in ans and goes to right of curr as left subtree
                    //is already traversed
                    temp->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};