class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int temp=0,maxi=INT_MIN;
    for(int i=0;i<arr.size();i++){
        temp+=arr[i];
        maxi=max(maxi,temp);
        if(temp<0) temp=0;
        
    }
    return maxi;
    }
};