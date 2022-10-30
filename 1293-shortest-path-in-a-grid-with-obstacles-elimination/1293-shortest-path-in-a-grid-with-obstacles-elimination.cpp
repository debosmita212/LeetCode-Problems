class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        //visited array
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
        queue<vector<int>> q;
        //x,y,current path length,number of obstacles we still can remove
        q.push({0,0,0,k});
        //BFS
        while(!q.empty()){
            auto t=q.front();
            int x=t[0],y=t[1];
            q.pop();
            
            //out of bound checking
            if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size()) continue;
            //reaches the destination
            if(x==grid.size()-1 && y==grid[0].size()-1) return t[2];//path length
            //obstacle
            if(grid[x][y]==1){
                //remove obstacle
                if(t[3]>0) t[3]--;
                else continue;
            }
            //already visited and not enough number of obstacles to be remove
            if(vis[x][y]!=-1 && vis[x][y]>=t[3]) continue;
            vis[x][y]=t[3];
            //4 directions
            q.push({x+1,y,t[2]+1,t[3]});
            q.push({x-1,y,t[2]+1,t[3]});
            q.push({x,y+1,t[2]+1,t[3]});
            q.push({x,y-1,t[2]+1,t[3]});
        }
        return -1;
    }
};