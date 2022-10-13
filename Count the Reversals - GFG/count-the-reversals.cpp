//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends



int countRev (string s)
{
    int n=s.length();
    //odd length cannot be balanced
    if(n%2==1) return -1;
    int open=0, close=0, rev=0;
    for(int i=0;i<n;i++){
        if(s[i]=='{') open++;
        else{
            if(open==0) close++;
            else open--;
        }
    }
    rev=(int)ceil(open/2.0)+ceil(close/2.0);
    return rev;
}