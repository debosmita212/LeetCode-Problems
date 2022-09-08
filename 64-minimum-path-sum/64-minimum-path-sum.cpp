class Solution {
public:
    //Recursive Approach-> T.C=O(2^N)
    //Memoization-> T.C=O(M*N) S.C=O(M*N)+O((M-1)+(N-1))
     //Tabulation-> T.C=O(M*N) S.C=O(M*N)
    //Space Optimization-> T.C=O(M*N) S.C=O(M)
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> prev(m,0);
        for(int i=0;i<n;i++){
            vector<int> curr(m,0);
            for(int j=0;j<m;j++){
                if(i==0 && j==0)
                    curr[j]=grid[0][0]; //base case
                else{
                    int up=grid[i][j];
                    int left=grid[i][j];
                    if(i>0)
                        up+=prev[j];
                    else
                        up+=1e9; //out of bound
                    if(j>0)
                        left+=curr[j-1];
                    else
                        left+=1e9; //out of bound
                    curr[j]=min(up,left);
                }
            }
            prev=curr;
        }
        return prev[m-1];
    }
};