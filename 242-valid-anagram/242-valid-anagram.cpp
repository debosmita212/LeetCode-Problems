class Solution {
public:
    bool isAnagram(string s, string t) {
        //if length not same 
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> mp;
        //count every character of string s frequency in map
        for(auto it:s){
            mp[it]++;
        }
        //if any character of t is present in map then reduce it's frequency
        for(auto it:t){
            if(mp.find(it)!=mp.end())
                mp[it]--;
        }
        //after all these, if there is still frequency left in map return false
        for(auto it:mp){
            if(it.second!=0)
                return false;
        }
        return true;
    }
};