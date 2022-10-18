class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();
        queue<pair<int,int>> q;
        //pushing all the 0s which are in the border
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O'){
                    q.push({i,j});
                }
            }
        }
        // 4 directions 
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        //doing BFS for those points
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            //mark boundary and adjacent 0s as safe
            for(auto it:dir){
                int nr=p.first+it[0];
                int nc=p.second+it[1];
                board[p.first][p.second]='S';
                if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc]=='O'){
                    board[nr][nc]='S';
                    q.push({nr,nc});
                }
            }
        }
        //if encounter still O make it X else encounters S make it O or continue
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='S')
                    board[i][j]='O';
                else continue;
            }
        }
    }
};