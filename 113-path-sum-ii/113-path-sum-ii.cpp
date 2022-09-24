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
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(TreeNode* root,int curr,int targetSum){
        if(root==NULL) return;
        //add to the curr and temp
        curr+=root->val;
        temp.push_back(root->val);
        //if leaf node and targetSum equals curr then path exists push into ans
        if(curr==targetSum && root->left==NULL && root->right==NULL)
            ans.push_back(temp);
        //traverse left and right
        dfs(root->left,curr,targetSum);
        dfs(root->right,curr,targetSum);
        temp.pop_back(); //backtracking
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,0,targetSum);
        return ans;
    }
};