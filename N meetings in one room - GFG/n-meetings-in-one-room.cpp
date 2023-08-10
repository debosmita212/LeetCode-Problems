//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    struct meeting{
      int s;
      int e;
      int num;
    };
    static bool comp(struct meeting a,struct meeting b){
        if(a.e<b.e) return true;
        else if(a.e>b.e) return false;
        else{
            return a.num<b.num;
        }
    }
    int maxMeetings(int start[], int end[], int n)
    {  
        struct meeting mt[n];
        for(int i=0;i<n;i++){
            mt[i].s=start[i];
            mt[i].e=end[i];
            mt[i].num=i+1;
        }
        sort(mt,mt+n,comp);
        int count=1;
        int temp=mt[0].e;
        for(int i=1;i<n;i++){
            if(mt[i].s>temp){
                count++;
                temp=mt[i].e;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends