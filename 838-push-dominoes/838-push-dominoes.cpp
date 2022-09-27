class Solution {
public:
    string pushDominoes(string s) {
        int n=s.size(),right=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                //make all left index L until we see any .
                if(right==-1){
                    //Step2
                    for(int j=i-1;j>=0 && s[j]=='.';--j){
                        s[j]='L';
                    }
                }
                else{
                    //we simultaneously change string from left and right side till two pointers reach each other. After that R moves back to -1.
                    for(int j=right+1,k=i-1;j<k;++j,--k){
                        s[j]='R';
                        s[k]='L';
                    }
                    right=-1;
                }
            }
            else if(s[i]=='R'){
                //we make all the indices upto that index R
                if(right!=-1){
                    for(int j=right+1;j<i;++j)
                        s[j]='R';
                }
                right=i;
            }
        }
        if(right!=-1){
            for(int j=right+1;j<n;j++)
                s[j]='R';
        }
        return s;
    }
};