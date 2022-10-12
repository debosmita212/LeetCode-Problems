//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
        int getScore(char c,char x[],int b[],int n){
            for(int i=0;i<n;i++){
                //if x contains that character return ascii value which was already in b
                if(x[i]==c) return b[i];
            }
            return (int)c; //else return ascii value of character itself
        }
      string maxSum(string w,char x[], int b[],int n){
          int max_so_far=INT_MIN, max_ending_here=0, start=0, end=0, s=0;
          for(int i=0;i<w.size();i++){
              max_ending_here+=getScore(w[i],x,b,n);
              
              //apply kadane
              if(max_so_far<max_ending_here){
                  max_so_far=max_ending_here;
                  start=s;
                  end=i;
              }
              
              if(max_ending_here<0){
                  max_ending_here=0;
                  s=i+1;
              }
          }
          return w.substr(start,end-start+1);
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends