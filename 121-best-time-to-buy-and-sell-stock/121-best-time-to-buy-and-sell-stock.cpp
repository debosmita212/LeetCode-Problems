class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int buy=0,sell=1,profit=0,n=arr.size();
    while(buy<n && sell<n){
        profit=max(profit,arr[sell]-arr[buy]);
        if(arr[sell]<arr[buy]){
            buy=sell;
        }
        sell++;
    }
    return profit;
    }
};