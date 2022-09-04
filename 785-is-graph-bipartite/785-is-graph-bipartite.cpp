class Solution {
public:
    bool solve(int src,vector<int> &color,vector<vector<int>> &graph){
        queue<int> q;
        q.push(src);
        color[src]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            //adjacents
            for(auto it:graph[node]){
                if(color[it]==-1){
                    //if not colored then color it opposite
                    //push into queue
                    color[it]=1-color[node];
                    q.push(it);
                }
                //if adjcent nodes are same color return false
                else if(color[it]==color[node])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        //color array initialized with -1
        vector<int> color(n,-1);
        //for each component
        for(int i=0;i<n;i++){
            //if not colored
            if(color[i]==-1){
                if(solve(i,color,graph)==false) return false;
            }
        }
        return true;
    }
};