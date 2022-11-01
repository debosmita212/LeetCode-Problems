//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printSquare(int n) {
        for(int i=n;i>0;i--){
            for(int j=n;j>0;j--){
                if(j>i) cout<<j<<" ";
                else cout<<i<<" ";
            }
            int j=i;
            for(int k=2;k<=n;k++){
                if(j>k) cout<<j<<" ";
                else cout<<k<<" ";
            }
            cout<<endl;
        }
        
        for(int i=2;i<=n;i++){
            for(int j=n;j>0;j--){
                if(j>i) cout<<j<<" ";
                else cout<<i<<" ";
            }
            int j=i;
            for(int k=2;k<=n;k++){
                if(j>k) cout<<j<<" ";
                else cout<<k<<" ";
            }
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
        ob.printSquare(n);
    }
    return 0;
}
// } Driver Code Ends