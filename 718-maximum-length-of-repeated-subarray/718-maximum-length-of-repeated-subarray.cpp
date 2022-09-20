class Solution {
public:
    //Memoization-> T.C=O(N*M) S.C=O(N*M)+O(N)
    int f(vector<int>& nums1,vector<int>& nums2,int n,int m,int i,int j,
          vector<vector<int>> &dp){
        //base case->index out of bound
        if(i>=n || j>=m) return 0;
        int len=0;
        if(dp[i][j]!=-1) return dp[i][j];
        //if matches character count 1 and increment both
        if(nums1[i]==nums2[j]){
            len+=1+f(nums1,nums2,n,m,i+1,j+1,dp);
        }
        return dp[i][j]=len;
        
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,f(nums1,nums2,n,m,i,j,dp));
            }
        }
        return ans;
    }
};