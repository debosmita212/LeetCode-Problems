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
    TreeNode* build(int inStart,int inEnd,vector<int> &inorder,int preStart,int preEnd,
                   vector<int> &preorder,map<int,int> &mp){
        //base case ->out of bound
        if(inStart>inEnd || preStart>preEnd) return NULL;
        //first element in preorder is the root
        TreeNode* root=new TreeNode(preorder[preStart]);
        //find it's index inorder
        int inValue=mp[root->val];
        //Number of elements on left from root in inorder
        int numsLeft=inValue-inStart;
        //left subtree build
        root->left=build(inStart,inValue-1,inorder,preStart+1,preStart+numsLeft,preorder,mp);
        //right subtree build
        root->right=build(inValue+1,inEnd,inorder,preStart+numsLeft+1,preEnd,preorder,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //map the inorder to indexes
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        //build the tree with inorder and preorder
        TreeNode* root=build(0,inorder.size()-1,inorder,0,preorder.size()-1,preorder,mp);
        return root;
    }
};