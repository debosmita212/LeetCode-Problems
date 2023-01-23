//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
       stack<char> st;
       st.push(s[0]);
       for(int i=1;i<s.length();i++){
           if(st.empty()){
               st.push(s[i]);
               continue;
           } 
           if(st.top()==s[i]) st.pop();
           else st.push(s[i]);
       }
       string ans="";
       while(!st.empty()){
           ans.push_back(st.top());
           st.pop();
       }
       if(ans=="") return "-1";
       reverse(ans.begin(),ans.end());
       return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends