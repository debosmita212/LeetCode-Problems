class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int mod=1e9+7;
        vector<pair<int,int>> candidates(n);
        for(int i=0;i<n;i++){
            candidates[i]={efficiency[i],speed[i]};
        }
        //sorting in descending order of efficiency
        sort(candidates.rbegin(),candidates.rend());
        long speedSum=0,ans=0;
        //min-heap
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto [e,s]:candidates){
            pq.push(s);
            speedSum+=s;
            //if exceeds k then remove the smallest speed
            if(pq.size()>k){
                speedSum-=pq.top();
                pq.pop();
            }
            ans=max(ans,speedSum*e); //calculate the performance
        }
        return ans%mod;
    }
};