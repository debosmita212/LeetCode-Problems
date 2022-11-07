//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n=matrix.size();
	    //Find all pairs shortest path by trying all possible paths
	    for(int k=0;k<n;k++){ //try all intermediate nodes
	        for(int i=0;i<n;i++){ //try for all possible starting position
	            for(int j=0;j<n;j++){ //try for all possible ending position
	            //skip if k is unreachable from i or j is unreachable from k
	                if(matrix[i][k]==-1 || matrix[k][j]==-1)
	                    continue;
	                    //check if new distance is shorter via vertex k
	                int curr=matrix[i][k]+matrix[k][j];
	                if(matrix[i][j]==-1)
	                    matrix[i][j]=curr;
	                else
	                    matrix[i][j]=min(matrix[i][k]+matrix[k][j],matrix[i][j]);
	            }
	        }
	    }
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends