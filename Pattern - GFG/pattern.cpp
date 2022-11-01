//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printDiamond(int n) {
        int leftSpace=n-1;
        //upper pattern print
        for(int i=1;i<=n;i++){
            //spaces
            for(int j=leftSpace;j>0;j--)
                cout<<" ";
                //stars
            for(int k=0;k<i;k++)
                cout<<"* ";
            leftSpace--;
            cout<<endl;
        }
        //lower pattern print
        int sp=0;
        for(int i=n;i>=1;i--){
            //spaces
            for(int j=0;j<sp;j++)
                cout<<" ";
                //stars
            for(int k=1;k<=i;k++)
                cout<<"* ";
            sp++;
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