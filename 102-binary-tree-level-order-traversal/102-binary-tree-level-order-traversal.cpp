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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<pair<TreeNode*,int>> q; //Node,level
        q.push({root,0}); //pushing the root with level 0
        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            //for every level
            for(int i=0;i<size;i++){
                //pop the front and access the node and level
                auto it=q.front();
                q.pop();
                TreeNode* node=it.first;
                int level=it.second;
                //pushing node value into array
                temp.push_back(node->val);
                //if left and right child exist push them into queue with updated level
                if(node->left){
                    q.push({node->left,level+1});
                }
                if(node->right){
                    q.push({node->right,level+1});
                }
            }
            //push array into ans and go for next level
            ans.push_back(temp);
        }
        return ans;
    }
};