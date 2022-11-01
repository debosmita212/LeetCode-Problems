//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        //upper triangle
        int sp=0;
        for(int i=n;i>=1;i--){
            for(int j=0;j<i;j++)
                cout<<"*";
            for(int k=0;k<sp;k++)
                cout<<"  ";
            sp++;
            for(int j=0;j<i;j++)
                cout<<"*";
            cout<<endl;
        }
        //lower triangle
        sp=n-1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++)
                cout<<"*";
            for(int k=sp;k>0;k--)
                cout<<"  ";
            sp--;
            for(int j=0;j<i;j++)
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