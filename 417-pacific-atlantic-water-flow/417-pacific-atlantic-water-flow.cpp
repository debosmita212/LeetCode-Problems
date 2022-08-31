class Solution {
public:
    int n,m;
    // Go througout the adjacent if the adjacent's height is more or equal to current height
    void dfs(vector<vector<int>> &grid,vector<vector<bool>> &flag,int x,int y){
        flag[x][y]=true;
        
        if(x-1>=0 && !flag[x-1][y] && grid[x-1][y]>=grid[x][y])
            dfs(grid,flag,x-1,y);
        if(x+1<n && !flag[x+1][y] && grid[x+1][y]>=grid[x][y])
            dfs(grid,flag,x+1,y);
        if(y-1>=0 && !flag[x][y-1] && grid[x][y-1]>=grid[x][y])
            dfs(grid,flag,x,y-1);
        if(y+1<m && !flag[x][y+1] && grid[x][y+1]>=grid[x][y])
            dfs(grid,flag,x,y+1);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        
        vector<vector<bool>> flag1(n,vector<bool>(m));
        vector<vector<bool>> flag2(n,vector<bool>(m));
        vector<vector<int>> ans;
        
        // Pacific
		// Do DFS starting from upper border and left border
		// Mark true in flag1 if possible
        for(int i=0;i<n;i++){
            dfs(heights,flag1,i,0);
        }
        for(int i=1;i<m;i++){
            dfs(heights,flag1,0,i);
        }
        
        // Atlantic
		// Do DFS starting from bottom border and right border
		// Mark true in flag1 if possible
        for(int i=0;i<n;i++){
            dfs(heights,flag2,i,m-1);
        }
        for(int i=0;i<m-1;i++){
            dfs(heights,flag2,n-1,i);
        }
        
        //Add cordinate to ans if both flag1 and flag2 is equal to true
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(flag1[i][j] && flag2[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};