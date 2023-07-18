//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        //Upper triangle
        for(int i=1;i<=n;i++){
            //left stars
            for(int j=1;j<=i;j++)
                cout<<"*";
            //gap
            for(int j=i;j<n;j++)
                cout<<" ";
            for(int j=i;j<n;j++)
                cout<<" ";
            //stars
            for(int j=1;j<=i;j++)
                cout<<"*";
            cout<<endl;
        }
        //lower triangle
        for(int i=1;i<n;i++){
            //stars
            for(int j=i;j<n;j++)
                cout<<"*";
            //gaps
            for(int j=1;j<=i;j++)
                cout<<" ";
            for(int j=1;j<=i;j++)
                cout<<" ";
            //stars
            for(int j=i;j<n;j++)
                cout<<"*";
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