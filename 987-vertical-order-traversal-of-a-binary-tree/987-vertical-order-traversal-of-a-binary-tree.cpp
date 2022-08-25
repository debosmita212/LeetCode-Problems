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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        //multisets for duplicates elements to store
        map<int,map<int,multiset<int>>> mp; //level,vertical lines, nodes
        queue<pair<TreeNode*,pair<int,int>>> qp; //Node,vertical,level
        qp.push({root,{0,0}});
        while(!qp.empty()){
            //pop the front
            auto temp=qp.front();
            qp.pop();
            //accessing node,vertical,level
            TreeNode* node=temp.first;
            int y=temp.second.first;
            int x=temp.second.second;
            //insert into map
            mp[y][x].insert(node->val);
            //if left child exists push into queue vertical -1 level +1
            if(node->left){
                qp.push({node->left,{y-1,x+1}});
            }
            //if right child exists push into queue vertical +1 level +1
            if(node->right){
                qp.push({node->right,{y+1,x+1}});
            }
        }
        for(auto it:mp){
            vector<int> col;
            //for a particular vertical pushes all elements in its multiset into ans
            for(auto p:it.second){
                col.insert(col.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};