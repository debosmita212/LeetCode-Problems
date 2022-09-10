class Solution {
public:
    //Recursive-> Exponential Time Complexity
    //Memoization-> T.C=O(N*2xK) S.C=O(N*2xK)+O(N)
    int f(vector<int>& prices,int n,int ind,int buy,int cap,
         vector<vector<vector<int>>> &dp){
        //base case
        if(ind==n || cap==0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int profit;
        if(buy==0){
            //buy the stock-> maximum of not buy and buy 
            profit=max(0+f(prices,n,ind+1,0,cap,dp),
                       -prices[ind]+
                       f(prices,n,ind+1,1,cap,dp));
        }
        if(buy==1){
            //sell the stock-> maximum of not sell and sell 
            profit=max(0+f(prices,n,ind+1,1,cap,dp)
                       ,prices[ind]+
                       f(prices,n,ind+1,0,cap-1,dp));
        }
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(prices,n,0,0,k,dp);
    }
};