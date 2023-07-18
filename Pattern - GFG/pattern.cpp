//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printDiamond(int n) {
        // Upper triangle
        for(int i=1;i<=n;i++){
            //gaps
            for(int j=i;j<=n-1;j++)
                cout<<" ";
            //stars
            for(int j=1;j<=i;j++)
                cout<<"* ";
            cout<<endl;
        }
        //Lower triangle
        for(int i=n;i>=1;i--){
            //gap
            for(int j=n;j>i;j--)
                cout<<" ";
            //stars
            for(int j=i;j>=1;j--)
                cout<<"* ";
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
        ob.printDiamond(n);
    }
    return 0;
}
// } Driver Code Ends