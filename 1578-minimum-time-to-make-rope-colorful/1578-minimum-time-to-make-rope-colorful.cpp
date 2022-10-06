class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res=0,n=colors.size(),max_cost=0;
        for(int i=0;i<n;i++){
            if(i>0 && colors[i]!=colors[i-1])
                max_cost=0; //not consecutive
            res=res+min(max_cost,neededTime[i]);
            max_cost=max(max_cost,neededTime[i]);
        }
        return res;
    }
};