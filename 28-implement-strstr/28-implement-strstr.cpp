//KMP->T.C=O(M+N)
class Solution {
public:
    vector<int> kmpProcess(string str){
        int n=str.length();
        vector<int> lps(n,0);//initialized with 0
        //start from 1
        for(int i=1,len=0;i<n;){
            if(str[i]==str[len]){
                lps[i++]=++len;//as we are counting from 1 index
            }
            else if(len!=0){
                len=lps[len-1];//don't increment i
            }
            else{
                lps[i++]=0;
            }
        }
        return lps;
    }
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        int n=haystack.length();
        int m=needle.length();
        
        //Create LPS array for pattern
        vector<int>lps=kmpProcess(needle);
        for(int i=0,j=0;i<n;){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            if(j==m)//matches return index
                return i-j;
            //mismatch after j matches
            if(i<n && haystack[i]!=needle[j]){
                //Don't match lps[0...lps[j-1]] characters,they will match anyway
                if(j!=0)
                    j=lps[j-1];
                else
                    i++; //when already j=0
            }
        }
        return -1;
    }
};