class Solution {
public:
    string countAndSay(int n) {
        //base case
        if(n==1) return "1";
        //recursive call
        string s=countAndSay(n-1);
        string res="";
        int count=0;
        for(int i=0;i<s.length();i++){
            count++;
            //if it reaches the end or next character does not match
            if(i==s.length() || s[i]!=s[i+1]){
                //add to string and reinitialized count to 0 for next character
                res=res+to_string(count)+s[i];
                count=0;
            }
        }
        return res;
    }
};