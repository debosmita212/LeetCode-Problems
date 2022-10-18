class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int fresh=0;
        queue<pair<pair<int,int>,int>> q; //Stores {{row,col},time}
        //calculate all the fresh oranges
        //push all rotten oranges in the queue
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0}); //already rotten so time is 0
                }
                if(grid[i][j]==1) fresh++;
            }
        }
        //Do BFS for those rotten oranges
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        int cnt=0;
        int time=0; //time here is level actually
        while(!q.empty()){
            pair<pair<int,int>,int> p=q.front();
            q.pop();
            for(auto it:dir){
                int nr=p.first.first+it[0];
                int nc=p.first.second+it[1];
                int t=p.second;
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    q.push({{nr,nc},t+1});
                    cnt++;
                }
                time=max(time,t); //Stores maximum time
            }
        }
        if(cnt==fresh) return time; //all becomes rotten
        return -1;
    }
};