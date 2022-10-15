class Solution {
public:
    //T.C=O(nlogn) S.C=O(N)
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        if(s.size()<3){
            return *max_element(s.begin(),s.end());
        }
        else{
            return *next(s.begin(),s.size()-3);
        }
    }
};