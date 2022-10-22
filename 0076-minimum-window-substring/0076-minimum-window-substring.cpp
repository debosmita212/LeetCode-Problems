class Solution {
public:
    /*
    Concept: Use two pointers start and end to represent a window. Move end to find a 
    valid window. When a valid window is found, move start to find a smaller window.
    */
    string minWindow(string s, string t) {
        //stores char,cnt
        unordered_map<char,int> mp;
        for(auto c:t) mp[c]++; //stores frequency of characters of string t in map
        int start=0,end=0,count=t.size(), minStart=0, minLen=INT_MAX,size=s.size();
        //while end less than size
        while(end<size){
            //if character in s exists in t, count decreases
            if(mp[s[end]]>0){
                count--;
            }
            mp[s[end]]--; //decrease the frequency, if char does not exist in t, 
            //frequency will be negative
            end++; //increase window size
            //found valid window where all characters of t exists in s
            while(count==0){
                //if it is less than minimum window size update window size and minStart
                if(end-start<minLen){
                    minStart=start;
                    minLen=end-start;
                }
                mp[s[start]]++; //stores frequency of start character in string s
                //when char exists in t, increase count
                if(mp[s[start]]>0){
                    count++;
                }
                start++; //decrease window size
            }
            
        }
        if(minLen!=INT_MAX) return s.substr(minStart,minLen);
        return "";
        
    }
};