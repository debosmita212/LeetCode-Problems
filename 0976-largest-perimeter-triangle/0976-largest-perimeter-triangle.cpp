class Solution {
public:
    /* IMP
    Condition for a triangle: a>=b>=c , a,b,c can form a triangle if a<b+c
    */
    int largestPerimeter(vector<int>& nums) {
        //sort the array
        sort(nums.begin(),nums.end());
        //loop executes for 1 time
        for(int i=nums.size()-1;i>1;i--){
            if(nums[i]<nums[i-1]+nums[i-2])
                return nums[i]+nums[i-1]+nums[i-2]; //perimeter
        }
        return 0; //cannot form a triangle
    }
};