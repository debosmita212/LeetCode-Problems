//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        //left pattern
        for(int i=1;i<=n;i++){
            //left numbers
            for(int j=1;j<=i;j++){
                if(j==i) cout<<j;
                else cout<<j<<" ";
            }
            //space 
            for(int j=n-1;j>=i;j--)
                cout<<"  ";
            //space
            for(int j=n-1;j>=i;j--)
                cout<<"  ";
                //right numbers
            for(int j=i;j>=1;j--)
                cout<<" "<<j;
            cout<<endl;
        }
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends