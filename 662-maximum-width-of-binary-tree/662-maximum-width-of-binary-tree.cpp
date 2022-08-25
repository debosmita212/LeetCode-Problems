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
//level order traversal with modification
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,int>> q; //node,level
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            //store the minimum index before iterating a level
            int mini=q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                //pop the front
                TreeNode* node=q.front().first;
                //update i=i-min
                int curr=q.front().second-mini;
                q.pop();
                //Store the leftmost and rightmost index
                if(i==0)
                    first=curr;
                if(i==size-1)
                    last=curr;
                //0-based indexing
                //if left child exists then push into queue with index 2*i+1
                if(node->left){
                    q.push({node->left,(long long)curr*2+1});
                }
                //if right child exists then push into queue with index 2*i+2
                if(node->right){
                    q.push({node->right,(long long)curr*2+2});
                }
            }
            //store max width 
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};