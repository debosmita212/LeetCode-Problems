class Solution {
public:
    //Recursive->T.C=O(2^N)~Exponential
    //Memoization-> T.C=O(N^2) S.C=O(N^2)+O(N) 
    int solve(int ind,int prev,vector<int> &nums,vector<vector<int>> &dp){
        //base case
        if(ind==nums.size()) return 0;
        //coordinate change
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        //not take case
        int len=0+solve(ind+1,prev,nums,dp);
        //take case
        if(prev==-1 || nums[ind]>nums[prev]){
            len=max(len,1+solve(ind+1,ind,nums,dp));
        }
        return dp[ind][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};