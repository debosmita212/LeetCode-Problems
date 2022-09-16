class Solution {
public:
    //Recursive T.C=O(2^N)
    //Memoization T.C=O(M*N) S.C=O(M*N)+O(N)
    int f(int i,int j,int n,int m,vector<int>& nums,vector<int>& multipliers,vector<vector<int>>&dp){
        //base case-> //m operations
        if(j==m) return 0; 
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        //left pick
        int left=nums[i]*multipliers[j]+f(i+1,j+1,n,m,nums,multipliers,dp);
        //right pick
        int right=nums[(n-1)-(j-i)]*multipliers[j]+f(i,j+1,n,m,nums,multipliers,dp);
        return dp[i][j]=max(left,right);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=nums.size(), m=multipliers.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,INT_MIN));
        return f(0,0,n,m,nums,multipliers,dp);
    }
};