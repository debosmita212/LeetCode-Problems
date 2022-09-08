class Solution {
public:
    //Recursive solution-> T.C=O(2^N) (Try all possible ways)
    //Memoization-> T.C=O(N*target) S.C=O(N*target)+O(target)
    //Tabulation-> T.C=O(N*target) S.C=O(N*target)
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        //base case
        dp[0][0]=0;
        for(int i=1;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                //not take
        int notTake=dp[i-1][j];
        //take
        int take=1e9;
        if(coins[i]<=j){
            take=1+dp[i][j-coins[i]]; //infinite number of coins supply so index remains same
        }
        dp[i][j]=min(take,notTake);
            }
        }
        int ans= dp[n-1][amount];
        if(ans<1e9) return ans;
        return -1;
    }
};