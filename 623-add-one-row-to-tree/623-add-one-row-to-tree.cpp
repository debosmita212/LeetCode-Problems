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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        //if depth is 1 then simply add root
        if(depth==1){
            TreeNode* newNode=new TreeNode(val);
            newNode->left=root;
            return newNode; //this is acting as new node now
        }
        //Simple BFS
        queue<TreeNode*> q;
        q.push(root);
        int count=0; //level count
        while(!q.empty()){
            /*Since we have to add values on all of the nodes present at that level
            so take out the size*/
            int n=q.size();
            count++; //increase level
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                
                //not reach till required level, simply push into queue
                if(count!=depth-1){
                    if(curr->left)
                        q.push(curr->left);
                    if(curr->right)
                        q.push(curr->right);
                }
                else{
                    //make new node to add
                    TreeNode* newNode=new TreeNode(val);
                    //first put left of curr to newNode
                    newNode->left=curr->left;
                    //now curr of left becomes newNode
                    curr->left=newNode;
                    
                    TreeNode* newNode2=new TreeNode(val);
                    //first put right of curr to newNode
                    newNode2->right=curr->right;
                    //now curr of right becomes newNode
                    curr->right=newNode2;
                }
            }
        }
        return root;
    }
};