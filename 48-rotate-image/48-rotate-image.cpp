class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        //swap elements 
        for(int i=0;i<row;i++){
            for(int j=i;j<col;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //reverse column wise
        for(int i=0;i<col;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};