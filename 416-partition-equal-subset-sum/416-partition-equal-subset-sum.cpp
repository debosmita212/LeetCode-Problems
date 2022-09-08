class Solution {
public:
    //Recursive solution-O(2^N)
    //Memoization- T.C=O(N*target) S.C=O(N*target)+O(target)
    //Tabulation- T.C=O(N*target) S.C=O(N*target)
    //Space Optimization T.C=O(N*target) S.C=O(target)
    bool solve(int n,int k,vector<int> &nums){
        vector<bool> prev(k+1,0), curr(k+1,0);
        //base case
        prev[0]=curr[0]=true;
        if(nums[0]<=k) prev[nums[0]]=true;
        for(int ind=1;ind<n;ind++){
            for(int j=1;j<=k;j++){
                bool notTake=prev[j];
                bool take=false;
                if(j>=nums[ind])
                    take=prev[j-nums[ind]];
                curr[j]=(take)||(notTake);
            }
            prev=curr;
        }
        return prev[k];
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