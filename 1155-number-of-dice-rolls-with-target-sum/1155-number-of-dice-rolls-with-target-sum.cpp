//Memoization
class Solution {
public:
    int mod=1e9+7;
    int solve(int n,int k,int target,vector<vector<int>> &dp){
        //base cases->(no dice and getting a 0)
        if(n==0 && target==0) return 1;
        //negative dice or negative target not possible
        if(n<=0 || target<=0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        
        int sum=0;
        //for k no. of faces calculate the sum
        for(int i=1;i<=k;i++){
            //reduce 1 dice and minus that face number from target
            sum=(sum%mod+solve(n-1,k,target-i,dp)%mod)%mod;
        }
        return dp[n][target]=sum;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);
    }
};