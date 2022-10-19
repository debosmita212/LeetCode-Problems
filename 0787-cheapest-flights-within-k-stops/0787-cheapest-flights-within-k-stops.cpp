class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //adjacency list
        vector<vector<pair<int,int>>> adj(n);
        //0:{1,100},{2,500} example of adjacency list
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        //distance array
        vector<int> dist(n,pow(10,4)*n);
        //to keep track of previous distance
        vector<int> prev(n);
        dist[src]=0;
        prev=dist;
        k++; //as k stops so travel for k+1 levels atmost
        while(k--){
            //traverse for adjacent
            for(int i=0;i<n;i++){
                for(int j=0;j<adj[i].size();j++){
                    int ind=adj[i][j].first;
                    int val=adj[i][j].second;
                    //update distance only if lesser distance has been found
                    if(dist[ind]>prev[i]+val){
                        dist[ind]=prev[i]+val;
                    }
                }
            }
            //update prev array to distance array
            prev=dist;
        }
        if(prev[dst]==pow(10,4)*n) return -1;
        return prev[dst];
    }
};