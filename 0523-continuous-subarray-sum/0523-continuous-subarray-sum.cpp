class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2) return false;
        unordered_map<int,int> mp;
        mp[0]=-1;
        int runningSum=0;
        for(int i=0;i<nums.size();i++){
            runningSum+=nums[i];
            if(k!=0)
                runningSum=runningSum%k;
            //check if it already present in map
            if(mp.find(runningSum)!=mp.end()){
                //current location-previous location>1 (as atleast 2 elements in subarray)
                if(i-mp[runningSum]>1) return true;
            }
            else{
                //not present in map, so store it
                mp[runningSum]=i;
            }
        }
        return false;
    }
};