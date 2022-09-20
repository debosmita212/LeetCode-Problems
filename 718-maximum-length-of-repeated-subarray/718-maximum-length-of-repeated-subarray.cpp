class Solution {
public:
    //Space Optimization-> T.C=O(N*M) S.C=O(M)
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<int> dp(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                //character matches 
                if(nums1[i]==nums2[j]){
                    if(i==0||j==0) dp[j]=1;
                    else dp[j]=1+dp[j-1];
                    ans=max(ans,dp[j]);
                }
                else dp[j]=0;
            }
        }
        return ans;
    }
};