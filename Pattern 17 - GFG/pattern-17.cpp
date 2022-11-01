//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        int cnt=n-1;
        char c='A';
        for(int i=1;i<=n;i++){
            for(int j=cnt;j>0;j--){
                cout<<" ";
            }
            cnt--;
            for(int j=0;j<i;j++){
                cout<<char(c+j);
            }
            if(i>1){
             for(int k=i-2;k>=0;k--){
                cout<<char(c+k);
            }   
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