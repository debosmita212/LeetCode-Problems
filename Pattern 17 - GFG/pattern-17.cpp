//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        for(int i=1;i<=n;i++){
            char ch='A';
            //gap
            for(int j=i;j<n;j++)
                cout<<" ";
            //characters
            int count=i;
            while(count){
                cout<<ch++;
                count--;
            }
            ch=ch-2;
            int temp=i-1;
            while(temp){
                cout<<ch--;
                temp--;
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