class Solution {
public:
    int trap(vector<int>& heights) {
        int leftMax=0,rightMax=0;
        int l=0,r=heights.size()-1;
        int ans=0;
        //Two-pointer approach
        while(l<=r){
            //Making sure if there exists a 2 on left then there must exists a 2 on right
            //to hold  the water in between
            if(heights[l]<=heights[r]){
                //if height becomes greater then cannot hold water so update leftMax
                if(heights[l]>leftMax){
                    leftMax=heights[l];
                }
                //else hold water of this amount
                else{
                    ans+=(leftMax-heights[l]);
                }
                //increment left pointer
                l++;
            }
            else{
                //making sure if there exists a 2 on right then there must exists a 2 on left
                //to hold water in between
                if(heights[r]>rightMax){
                    //if height becomes greater then cannot hold water so update rightMax
                    rightMax=heights[r];
                }
                else{
                    //else hold water of this amount
                    ans+=(rightMax-heights[r]);
                }
                //decrement right pointer
                r--;
            }
        }
        return ans;
    }
};