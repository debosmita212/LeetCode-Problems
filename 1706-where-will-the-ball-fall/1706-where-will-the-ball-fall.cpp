class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int> ans(m);
        for(int j=0;j<m;j++){
            int curr=j;
            int next=-1;
            for(int i=0;i<n;i++){
                next=curr+grid[i][curr];//if 1->right -1->left
                //ball is blocked by the wall or in between
                if(next<0 || next>=m || grid[i][curr]!=grid[i][next]){
                    curr=-1;
                    break;
                }
                //update curr
                curr=next;
            }
            //stores the column
            ans[j]=curr;
        }
        return ans;
    }
};