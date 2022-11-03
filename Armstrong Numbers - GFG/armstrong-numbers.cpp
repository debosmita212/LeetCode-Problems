//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        int number=n;
        int original=n;
        int armstrong=0;
        int digit=0;
        
        //generalized as digit maynot be 3 always
        while(number!=0){
            digit++;
            number=number/10;
        }
        while(n!=0){
            int d=n%10;
            armstrong+=pow(d,digit);
            n=n/10;
        }
        if(armstrong==original) return "Yes";
        return "No";
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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends