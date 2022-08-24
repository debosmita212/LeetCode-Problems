class Solution {
public:
    int compareVersion(string version1, string version2) {
        int c1=0;
        int c2=0;
        int n=version1.length();
        int m=version2.length();
        int i=0,j=0;
        
        //if any of them out of bound then out of loop
        while(i<n || j<m){
            //until encounter a "." count for c1
            while(i<n && version1[i]!='.'){
                c1=(c1*10)+(version1[i]-'0');
                i++;
            }
            //until encounter a "." count for c2
            while(j<m && version2[j]!='.'){
                c2=(c2*10)+(version2[j]-'0');
                j++;
            }
            //compare them
            if(c1>c2){
                return 1;
            }
            if(c2>c1)
                return -1;
            //reintialized them for next revision
            c1=c2=0;
            i++;j++;
        }
        return 0;
    }
};