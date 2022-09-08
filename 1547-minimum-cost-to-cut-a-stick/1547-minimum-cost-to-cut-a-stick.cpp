class Solution {
public:
    //Recursive T.C=Exponential
    //Memoization T.C=O(M*M) S.C=O(M*M)+O(M)
    int f(int low,int high,vector<int>&cuts,vector<vector<int>> &dp){
        //base case
        if(low+1==high) return 0;
        else if(dp[low][high]!=-1) return dp[low][high];
        else{
            int ans=INT_MAX;
            for(int i=low+1;i<high;i++){
                int notTake=f(i,high,cuts,dp);
                //as length denotes the cost
                int take=cuts[high]-cuts[low]+f(low,i,cuts,dp);
                int total=take+notTake;
                ans=min(ans,total);
            }
            return dp[low][high]=ans;
        }
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        //sort the cuts
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return f(0,m-1,cuts,dp);
    }
};