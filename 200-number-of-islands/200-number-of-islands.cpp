//DFS Solution
class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j){
        //base case-> out of bound or water
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || grid[i][j]=='0')
            return;
        //make it water
        grid[i][j]='0';
        //4 directions
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int temp=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                //if island
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    temp++;
                }
            }
        }
        return temp;
    }
};