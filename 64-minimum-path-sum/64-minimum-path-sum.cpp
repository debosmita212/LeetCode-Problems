class Solution {
public:
    //Recursive Approach-> T.C=O(2^N)
    //Memoization-> T.C=O(M*N) S.C=O(M*N)+O(N)
     //Tabulation-> T.C=O(M*N) S.C=O(M*N)
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)
                    dp[i][j]=grid[0][0]; //base case
                else{
                    int up=grid[i][j];
                    int left=grid[i][j];
                    if(i>0)
                        up+=dp[i-1][j];
                    else
                        up+=1e9; //out of bound
                    if(j>0)
                        left+=dp[i][j-1];
                    else
                        left+=1e9; //out of bound
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};