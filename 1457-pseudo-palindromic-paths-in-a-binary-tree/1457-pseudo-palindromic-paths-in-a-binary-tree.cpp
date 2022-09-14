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
    int count=0;
    //preorder
    void dfs(TreeNode* root,vector<int> mp){
        //base case
        if(root==NULL) return;
        //increment the count of node's value
        mp[root->val]++;
        //check if child node and then for palindrome by odd count technique
        if(root->left==NULL && root->right==NULL){
            int odd_count=0;
            for(auto it:mp){
                if(it%2==1)
                    odd_count++;
            }
            if(odd_count<=1) //palindrome as odd_count is atmost 1
                count++;
            return;
        }
        dfs(root->left,mp);
        dfs(root->right,mp);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        //as tree consists of 0-9 
        //initialize with the count of 0
        vector<int> mp(10,0); 
        dfs(root,mp);
        return count;
    }
};