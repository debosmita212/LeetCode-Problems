class Solution {
public:
    //Recursive solution-> T.C=Exponential
    //Memoization-> T.C=O(M*N) S.C=O(M*N) +O(N)
    int solve(int i,int j,string &word1,string &word2,vector<vector<int>> &dp){
        //base case
        if(i<0) return j+1; //j+1 number of insertions
        if(j<0) return i+1; //i+1 number of deletions
        if(dp[i][j]!=-1) return dp[i][j];
        //matches
        if(word1[i]==word2[j]){
            dp[i][j]=0+solve(i-1,j-1,word1,word2,dp);
        }
        else{
            dp[i][j]=1+min(solve(i,j-1,word1,word2,dp),//insertion
                min(solve(i-1,j,word1,word2,dp)//deletion
                ,solve(i-1,j-1,word1,word2,dp)));//updation
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int n=word1.length(), m=word2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,word1,word2,dp);
    }
};