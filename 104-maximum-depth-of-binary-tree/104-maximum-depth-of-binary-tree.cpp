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
//Find the level ->just do level order traversal and simultaenously increase the level
class Solution {
public:
    int maxDepth(TreeNode* root) {
        vector<vector<int>> ans;
        int level=0;
        if(root==NULL) return level;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            level++;
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode* t=q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            ans.push_back(temp);
        }
        return level;
    }
};