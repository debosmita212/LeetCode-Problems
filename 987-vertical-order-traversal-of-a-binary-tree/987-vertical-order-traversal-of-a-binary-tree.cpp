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
        
        //multiset for storing duplicate nodes values
        map<int,map<int,multiset<int>>> mp;//vertical,level,nodes
        queue<pair<TreeNode*,pair<int,int>>> q;//node,level,vertical
        q.push({root,{0,0}}); //pushing root with 0 level and 0 vertical
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            //Accessing node,level and vertical
            TreeNode* node=temp.first;
            int lev=temp.second.first;
            int ver=temp.second.second;
            mp[ver][lev].insert(node->val); //map insert node's value
            //left child-> vertical=ver-1,level=lev+1
            if(node->left){
                q.push({node->left,{lev+1,ver-1}});
            }
            //right child-> vertical=ver+1,level=lev+1
            if(node->right)
                q.push({node->right,{lev+1,ver+1}});
        }
        for(auto it:mp){
            vector<int> cols;
            //for a particular vertical push all it's multiset elements into ans
            for(auto p:it.second){
                cols.insert(cols.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(cols);
        }
        return ans;
    }
};