//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int sum=0;
        int maxi=0;
        unordered_map<int,int> mp; //sum to first occurence
        for(int i=0;i<N;i++){
            sum+=A[i];
            //sum itself become k so array length upto this must be the maximum
            if(sum==K){
                maxi=max(maxi,i+1);
            }
            //if map already contains sum-k subarray sum then in between subarray sum must 
            //be having sum k, update the maxi
            if(mp.find(sum-K)!=mp.end()){
                maxi=max(maxi,i-mp[sum-K]);
            }
            //if map doesn't already contains sum then only push it because the first 
            //occurence will always gives the maximum length
            if(mp.count(sum)==0){
                mp[sum]=i;
            }
        }
        return maxi;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends