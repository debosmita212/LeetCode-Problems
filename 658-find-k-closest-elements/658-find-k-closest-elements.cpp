class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0,r=arr.size()-1;
        while(r-l+1>k){
            if(arr[r]-x >= x-arr[l]) r--;
            else l++;
        }
        vector<int> ans;
        for(int i=l;i<=r;i++)
            ans.push_back(arr[i]);
        return ans;
    }
};