class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        map<int,priority_queue<int,vector<int>,greater<int>>> mp;
        //iterate each row
        for(int i=0;i<n;i++){
            //iterate each column
            for(int j=0;j<m;j++){
                //for each mat[i][j] add it to the corresponding priority queue
                mp[i-j].push(mat[i][j]);
            }
        }
        //iterate each row
        for(int i=0;i<n;i++){
            //iterate each col
            for(int j=0;j<m;j++){
                //mp[i-j].top() would return the smallest number in the current queue
                //we can just perform inplace replacement here
                mat[i][j]=mp[i-j].top();
                //as we don't need this value anymore,pop it out so that next cell
                //would get the smallest value
                mp[i-j].pop();
            }
        }
        return mat;
    }
};