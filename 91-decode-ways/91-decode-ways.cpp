//Memoization-> T.C=O(n) S.C=O(n)
class Solution {
public:
    int dp[102];
    int solve(int ind,int n,string &s){
        //base cases-> negative index and character is 0
        if(ind<n && s[ind]=='0') return 0;
        //reaches last
        if(ind>=n) return 1;
        if(dp[ind]!=-1) return dp[ind];
        int ways=0;
        //pick single covers '1' to '9'
        if(s[ind]!='0')
            ways=solve(ind+1,n,s); //goes to next index
        //pick couple covers '10' to '26'
        if(ind+1<n && ((s[ind]=='1' && s[ind+1]<='9')||(s[ind]=='2' && s[ind+1]<'7')))
            ways+=solve(ind+2,n,s);//goes to ind+2 as we take 2 elements 
        return dp[ind]=ways;
    }
    int numDecodings(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n,s);
    }
};