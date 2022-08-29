class Solution {
public:
    void dfs(vector<vector<char>> &grid,int i,int j){
        //base case->out of bound
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || grid[i][j]=='0') return;
        grid[i][j]='0'; //mark visited as 0
        dfs(grid,i+1,j); //down
        dfs(grid,i-1,j);  //up
        dfs(grid,i,j-1);  //left
        dfs(grid,i,j+1);  //right
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int temp=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    temp++;
                }
            }
        }
        return temp;
    }
};