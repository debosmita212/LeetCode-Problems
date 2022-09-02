class Solution {
public:
    void solve(vector<vector<int>>& image, int sr, int sc, int color,int curr){
        //out of bound so return
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size()) return;
        //not same color return
        if(curr!=image[sr][sc]) return;
        //mark as same color
        image[sr][sc]=color;
        //go for four directions
        solve(image,sr-1,sc,color,curr);
        solve(image,sr+1,sc,color,curr);
        solve(image,sr,sc-1,color,curr);
        solve(image,sr,sc+1,color,curr);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //DFS Traversal
        //Avoid infinite loop if new and old color are same
        if(image[sr][sc]==color) return image;
        solve(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};