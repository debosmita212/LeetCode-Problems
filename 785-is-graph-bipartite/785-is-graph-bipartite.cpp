//DFS Solution
class Solution {
public:
    bool solve(int node,vector<int> &color,vector<vector<int>> &graph){
        //color the node
        if(color[node]==-1) color[node]=1;
        //check for adjacent
        for(auto it:graph[node]){
            //if not colored
            if(color[it]==-1){
                //color adjacent with opposite color
                color[it]=1-color[node];//if 1 then 0 ,if 0 then 1
                //if anyone returns false, then return false
                if(solve(it,color,graph)==false)
                    return false;
            }
            //if adjacent have the same colors then return false
            else if(color[it]==color[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        //color array initialized with -1
        vector<int> color(n,-1);
        //check for component
        for(int i=0;i<n;i++){
            //if not colored,color it
            if(color[i]==-1){
                if(solve(i,color,graph)==false) return false;
            }
        }
        return true;
    }
};