class Solution {
public:
    //SEE discussion section-> chirantan722
    int dfs(vector<int>& jobDifficulty, int d,int pos,vector<vector<int>> &dp,int n){
        //base cases
        if(d==0){
            //find the maximum of rest of array and return it
            int maxi=jobDifficulty[pos];
            for(int i=pos;i<n;i++)
                maxi=max(maxi,jobDifficulty[i]);
            return maxi;
        }
        int day=dp.size()-d;
        if(dp[day][pos]!=-1) return dp[day][pos];
        
        //trying out all possible ranges
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=pos;i<n-d;i++){
            maxi=max(maxi,jobDifficulty[i]);
            mini=min(mini,maxi+dfs(jobDifficulty,d-1,i+1,dp,n));
        }
        return dp[day][pos]=mini;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(d>n) return -1; //not possible
        vector<vector<int>> dp(d-1,vector<int>(n,-1));
        return dfs(jobDifficulty,d-1,0,dp,n);
    }
};