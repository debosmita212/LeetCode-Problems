class Solution {
public:
    //Recursive solution-> T.C=Exponential
    //Memoization-> T.C=O(M*N) S.C=O(M*N) +O(N)
    //Tabulation-> T.C=O(M*N) S.C=O(M*N) (1 based indexing)
    int minDistance(string word1, string word2) {
        int n=word1.length(), m=word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++) dp[0][j]=j;
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //matches
        if(word1[i-1]==word2[j-1]){
            dp[i][j]=0+dp[i-1][j-1];
        }
        else{
            dp[i][j]=1+min(dp[i][j-1],//insertion
                min(dp[i-1][j],//deletion
                dp[i-1][j-1]));//updation
        }
            }
        }
        return dp[n][m];
    }
};