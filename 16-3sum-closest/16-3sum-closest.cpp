class Solution {
public:
    //T.C=O(NlogN)+O(N^2) S.C=O(1)
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mini=INT_MAX,ans;
        //3sum approach
        for(int i=0;i<n-2;i++){
            int l=i+1,r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                //updating the sum if closest
                if(abs(sum-target)<mini){
                    mini=abs(sum-target);
                    ans=sum;
                }
                if(sum<target) l++;
                else if(sum>target) r--;
                else{
                    //equal summ is found no need to check further so break
                    ans=sum;
                    i=n-2; //for breaking the outer for loop
                    break;
                }
            }
        }
        return ans;
    }
};