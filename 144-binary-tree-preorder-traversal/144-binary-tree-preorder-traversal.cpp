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
//Morris traversal-> Root-Left-Right
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;
        //until curr exists
        while(curr!=NULL){
            //if left subtree does not exist
            if(curr->left==NULL){
                //push the root val and goes to right
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                //left subtree exists
                TreeNode* temp=curr->left;
                //go to the rightmost element on left subtree
                while(temp->right && temp->right!=curr)
                    temp=temp->right;
                //points to null then link it with curr
                //push the curr val to ans and points curr to left
                if(temp->right==NULL){
                    temp->right=curr;
                    ans.push_back(curr->val);
                    curr=curr->left;
                }
                else{
                    //already points to curr break the link and point to the right
                    //as left subtree is already traversed
                    temp->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};