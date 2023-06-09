//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> prefSum; //prefSum,firstOccurence
        int sum=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            //if already the sum is 0, that should be longest
            if(sum==0){
                maxi=i+1;
            }
            //already prefixSum present, so in between the subarray sum must be 0
            else if(prefSum.find(sum)!=prefSum.end()){
                maxi=max(maxi,i-prefSum[sum]);
            }
            //else store the first occurence
            else prefSum[sum]=i;
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends