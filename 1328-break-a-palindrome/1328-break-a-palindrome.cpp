class Solution {
public:
    /*
    Check half of the string,
replace a non 'a' character to 'a'.

If only one character, return empty string.
Otherwise repalce the last character to 'b'
    */
    //T.C=O(N) S.C=O(N)
    string breakPalindrome(string S) {
        int n=S.size();
        for(int i=0;i<n/2;i++){
            if(S[i]!='a'){
                S[i]='a';
                return S;
            }
        }
        S[n-1]='b';
        if(n<2) return "";
        return S;
    }
};