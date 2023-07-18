//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        int flag=1;
        for(int i=1;i<=n;i++){
            flag=(i%2==0)?0:1;
            for(int j=1;j<=i;j++){
                cout<<flag<<" ";
                flag=flag==1?0:1;
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
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends