class Solution {
public:
    int mod=1e9+7;
    //Dynamic Programming problem explore all paths
    int solve(vector<int>& locations, int start, int finish, int fuel, vector<vector<int>> &dp){
        int ans=0;
        //base case
        //we don't need to stop here because we only need to count how many times
        //it passes the finish location
        if(start==finish) ans++;
        if(dp[start][fuel]!=-1) return dp[start][fuel];
        
        for(int i=0;i<locations.size();i++){
            if(i!=start && abs(locations[i]-locations[start])<=fuel){
                ans+=solve(locations,i,finish,
                           fuel-abs(locations[i]-locations[start]),dp);
                ans%=mod;
            }
        }
        return dp[start][fuel]=ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(105,vector<int>(205,-1));//location,fuel
        return solve(locations,start,finish,fuel,dp);
    }
};