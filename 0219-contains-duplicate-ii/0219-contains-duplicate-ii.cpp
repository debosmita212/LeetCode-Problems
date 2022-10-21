class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       /* unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            //comparing with the previous index
            if(mp.find(nums[i])!=mp.end() && i-mp[nums[i]]<=k) return true;
            mp[nums[i]]=i; //mapping the latest index to element
        }
        return false;*/
        
        //Unordered_set sliding window solution contains only k elements
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            if(i>k){
                s.erase(nums[i-k-1]); //reduce the window size
            }
            //the s.insert() returns a pair, the second element in the pair is set
            //to true if a new element was inserted or false if an equivalent element already 
            //existed
            if(!s.insert(nums[i]).second) return true;
        }
        return false;
    }
};