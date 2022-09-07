class Solution {
public:
    //Recursive approach->T.C=Exponential
    //Memoization-> T.C=O(N*M) S.C=O(N*M) +O(M+N)//Stack space
    int solve(string &text1,string &text2,int i,int j,vector<vector<int>> &dp){
        //base case
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        //match case
        if(text1[i]==text2[j]){
            dp[i][j]=1+solve(text1,text2,i-1,j-1,dp);
        }
        else{
            //do not match
            dp[i][j]=max(solve(text1,text2,i-1,j,dp),solve(text1,text2,i,j-1,dp));
        }
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(),m=text2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(text1,text2,n-1,m-1,dp);
    }
};