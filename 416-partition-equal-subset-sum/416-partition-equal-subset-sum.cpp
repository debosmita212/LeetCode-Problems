class Solution {
public:
    //Recursive solution-O(2^N)
    //Memoization- T.C=O(N*target) S.C=O(N*target)+O(target)
    bool f(int ind,int k,vector<int> &nums,vector<vector<int>> &dp){
        //base case
        if(k==0) return true; //target becomes 0
        if(ind==0) return (nums[0]==k);
        if(dp[ind][k]!=-1) return dp[ind][k];
        bool notTake=f(ind-1,k,nums,dp);
        bool take=false;
        if(k>=nums[ind])
            take=f(ind-1,k-nums[ind],nums,dp);
        return dp[ind][k]=take||notTake;
    }
    bool solve(int n,int k,vector<int> &nums){
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return f(n-1,k,nums,dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        //odd sum can't be divided into equal subset sum
        if(sum%2!=0) return false;
        //we need to find one subset of sum sum/2 as another one definitely have the
        //same sum
        int target=sum/2;
        int n=nums.size();
        return solve(n,target,nums);
    }
};