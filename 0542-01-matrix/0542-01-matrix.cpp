class Solution {
public:
    /*
    As multiple sources and multiple destinations use BFS
    and cost is unit and no change of cost
    */
    bool isvalid(int i,int j,int m,int n)
    {
        if(i==m||j==n||j<0||i<0)
            return false;
        return true;
    }
    //direction array
    vector<vector<int>> dir={{1,0},{0,1},{0,-1},{-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int,int>> q;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dis(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {   
                //as 0 distance from itself
                if(matrix[i][j]==0)
                { 
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        //use BFS
        while(!q.empty())
        {
            pair<int,int> curr=q.front();
            q.pop();
            for(auto& x:dir) //iterate for 4 directions
            {
                int a=curr.first+x[0];
                int b=curr.second+x[1];
                //checking out of bound and unvisited condition
                if(isvalid(a,b,m,n)&&dis[a][b]==-1)
                {
                    q.push({a,b});
                    dis[a][b]=dis[curr.first][curr.second]+1; //updating with level+1
                }
            }
        }
        return dis;
    }
};