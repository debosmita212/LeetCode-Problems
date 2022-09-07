class Solution {
public:
    //Recursive solution-> T.C=Exponential
    //Memoization-> T.C=O(M*N) S.C=O(M*N) +O(N)
    //Tabulation-> T.C=O(M*N) S.C=O(M*N) (1 based indexing)
    //Space Optimization-> T.C=O(M*N) S.C=O(M) (1 based indexing)
    int minDistance(string word1, string word2) {
        int n=word1.length(), m=word2.length();
        vector<int> prev(m+1,0), curr(m+1,0);
        for(int j=0;j<=m;j++) prev[j]=j;
        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                //matches
        if(word1[i-1]==word2[j-1]){
            curr[j]=0+prev[j-1];
        }
        else{
            curr[j]=1+min(curr[j-1],//insertion
                min(prev[j],//deletion
                prev[j-1]));//updation
        }
            }
            prev=curr;
        }
        return prev[m];
    }
};