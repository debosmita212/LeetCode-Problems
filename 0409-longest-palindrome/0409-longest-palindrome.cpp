class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++) mp[s[i]]++;
        int cnt=0;
        for(auto it:mp){
            //odd frequencies count
            if(it.second%2!=0) cnt++;
        }
        if(cnt>1){
            return s.length()-cnt+1;
        }
        return s.length();
    }
};