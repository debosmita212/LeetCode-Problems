//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        //make all 0s -1
        for(int i=0;i<N;i++){
            if(arr[i]==0) arr[i]=-1;
        }
        //Now find the largest subarray whose sum is equal to 0 as it'll contain equal number of 1s and -1s
        int maxi=0;
        int sum=0;
        unordered_map<int,int> mp; //sum,firstOccurence
        for(int i=0;i<N;i++){
            sum+=arr[i];
            if(sum==0){
                maxi=i+1; //maximum length till now
            }
            else if(mp.find(sum)!=mp.end()){
                maxi=max(maxi,i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends