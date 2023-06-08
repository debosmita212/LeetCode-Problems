//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
        unordered_map<int,int> mp;
        //element to first index mapping
        for(int i=0;i<n;i++){
            if(mp.find(arr[i])!=mp.end()){
                continue;
            }
            mp[arr[i]]=i;
        }
        //element to last occurence
        unordered_map<int,int> mp1;
        for(int i=0;i<n;i++){
            if(mp1.find(arr[i])!=mp1.end()){
                mp1[arr[i]]=i;
            }
            mp1[arr[i]]=i;
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,mp1[arr[i]]-mp[arr[i]]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.maxDistance(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends