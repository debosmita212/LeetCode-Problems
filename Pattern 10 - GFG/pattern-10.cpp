//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Solution{
public:
    void printTriangle(int n) {
        //upper pattern print
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++)
                cout<<"* ";
            cout<<endl;
        }
        //lower pattern print
        for(int i=n-1;i>=1;i--){
            for(int j=0;j<i;j++)
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
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends