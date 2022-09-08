class Solution {
public:
    //Recursive Approach-> T.C=O(2^N)
    //Memoization-> T.C=O(M*N) S.C=O(M*N)+O(N)
    int f(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
        //base case->reached destination
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9; //do not consider
        if(dp[i][j]!=-1) return dp[i][j];
        //up
        int up=grid[i][j]+f(i-1,j,grid,dp);
        //left
        int left=grid[i][j]+f(i,j-1,grid,dp);
        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,grid,dp);
    }
};