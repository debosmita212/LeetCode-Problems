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
    TreeNode* build(int inStart,int inEnd,vector<int> &inorder,int postStart,int postEnd,vector<int> 
                   &postorder,map<int,int> &mp){
        //base cases->out of bound
        if(inStart>inEnd || postStart>postEnd) return NULL;
        //last element of postorder is root
        TreeNode* root=new TreeNode(postorder[postEnd]);
        //find it's index in inorder
        int inValue=mp[root->val];
        //nums left on root in inorder
        int numsLeft=inValue-inStart;
        //left subtree build
        root->left=build(inStart,inValue-1,inorder,postStart,postStart+numsLeft-1,postorder,mp);
        //right subtree build
        root->right=build(inValue+1,inEnd,inorder,postStart+numsLeft,postEnd-1,postorder,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //map inorder to indexes
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        //build tree from postorder and inorder
        TreeNode* root=build(0,inorder.size()-1,inorder,0,postorder.size()-1,postorder,mp);
        return root;
    }
};