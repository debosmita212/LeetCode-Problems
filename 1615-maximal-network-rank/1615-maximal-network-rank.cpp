class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        //count array
        vector<int> count(n);
        //direction 2d array
        vector<vector<int>> dir(n,vector<int>(n));
        for(auto it:roads){
            count[it[0]]++;
            count[it[1]]++;
            dir[it[0]][it[1]]++;
            dir[it[1]][it[0]]++;
        }
        int rank=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                rank=max(rank,count[i]+count[j]-dir[i][j]);
            }
        }
        return rank;
    }
};