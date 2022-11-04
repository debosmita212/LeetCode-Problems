//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void f(int i,int n){
        //base case
        if(i>n) return;
        cout<<"GFG ";
        i++;
        f(i,n);
    }
    void printGfg(int N) {
        f(1,N);
    }
};


//{ Driver Code Starts.
/* Driver program to test printNos */
int main() {
    int T;

    // taking testcases
    cin >> T;

    while (T--) {
        int N;

        // input N
        cin >> N;
        Solution ob;
        // calling printNos() function
        ob.printGfg(N);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends