class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        for(int i:nums){
            if(nums[abs(i)-1]<0)
                res[0]=abs(i); //Repetitive number as it already contains -ve
            else
                nums[abs(i)-1]*=-1;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) res[1]=i+1; //Missing number
        }
        return res;
    }
};