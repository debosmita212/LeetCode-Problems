//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

//boils down to the question maximum points on the same line since then only the arrow can 
//hit the maximum ballons
//points which are on the same line they have same slope value
//so for each point we can calculate the slope values and find the maximum
class Solution {
  public:
    int mostBalloons(int N, pair<int, int> arr[]) {
        if(N<=2) return N; //starting and ending point of a line so 2 ballons
        int ans=2; //2 as in starting and ending point that is by default
        for(int i=0;i<N;i++){
            double x=arr[i].first;
            double y=arr[i].second;
            int count=0;
            unordered_map<double,int> mp; //slope,occurence of that slope
            for(int j=0;j<N;j++){
                double x1=arr[j].first;
                double y1=arr[j].second;
                //same point should be consider
                if(x1==x && y1==y){
                    count++;
                }
                else{
                    //calculate the slope and store the slope with frequency
                    double slope=(double)(y1-y)/(x1-x);
                    mp[slope]++;
                }
            }
            //now update the maximum
            auto it=mp.begin();
            while(it!=mp.end()){
                ans=max(ans,it->second+count);
                it++;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
}
// } Driver Code Ends