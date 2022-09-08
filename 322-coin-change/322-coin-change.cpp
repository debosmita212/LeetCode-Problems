class Solution {
public:
    //Recursive solution-> T.C=O(2^N) (Try all possible ways)
    //Memoization-> T.C=O(N*target) S.C=O(N*target)+O(target)
    int f(int i,int amount,vector<int> &coins,vector<vector<int>> &dp){
        //base case
        if(i==0){
            if(amount%coins[i]==0) return amount/coins[i];
            else
                return 1e9;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        //not take
        int notTake=0+f(i-1,amount,coins,dp);
        //take
        int take=1e9;
        if(coins[i]<=amount){
            take=1+f(i,amount-coins[i],coins,dp); //infinite number of coins supply so index remains same
        }
        return dp[i][amount]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= f(n-1,amount,coins,dp);
        if(ans<1e9) return ans;
        return -1;
    }
};