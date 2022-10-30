//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    //expire array
	    //as constraint says than maximum n would be 35 so it stays for 6 days
	    vector<long long int> expires(41,0);
	    long long cnt=1;//started with 1 chick
	    expires[6]=cnt; //as 1st chick gonna expires on 6th day
	    for(int i=1;i<n;i++){
	        cnt=cnt-expires[i]; //eliminate the dead chicks
	        expires[i+6]+=2*cnt; //as everyday 2 chicks are born
	        cnt+=cnt*2;//add the new born chicks
	    }
	    return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends