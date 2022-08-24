class Solution {
public:
    int strStr(string haystack, string needle) {
        //check if the substring present in haystack
        for(int i=0;i<haystack.length();i++){
            if(haystack.substr(i,needle.length())==needle){
                return i;
            }
        }
        return -1;
    }
};