//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++
//Memoization
class Solution{
    public:
    unordered_map<string,bool> mp;
    bool isScramble(string S1, string S2){
        if(S1==S2) return true;
        if(S1.length()<=1) return false;
        string key=S1+" "+S2;
        if(mp.count(key)) return mp[key];
        int n=S1.length();
        bool flag=false;
        for(int i=1;i<=n-1;i++){
            if(((isScramble(S1.substr(0,i),S2.substr(n-i,i))) &&
            (isScramble(S1.substr(i,n-i),S2.substr(0,n-i)))) ||
            ((isScramble(S1.substr(0,i),S2.substr(0,i))) &&
            (isScramble(S1.substr(i,n-i),S2.substr(i,n-i)))))
            {
                flag=true;
                break;
            }
        }
        return mp[key]=flag;
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends