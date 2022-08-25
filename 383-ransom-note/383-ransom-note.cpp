class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //count the frequency every character of ransomNote in map
        unordered_map<int,int> mp;
        for(int i=0;i<ransomNote.size();i++){
            mp[ransomNote[i]]++;
        }
        int count=0;
        //check if the char of magazine is already present in map
        //then decrement the frequency and increase the count
        for(int i=0;i<magazine.size();i++){
            if(mp.find(magazine[i])!=mp.end() && mp[magazine[i]]>0){
                count++;
                mp[magazine[i]]--;
                if(count==ransomNote.size())
                    return true;
            }
        }
        //if it is equal to ransomNote size then return true
       
        return false;
    }
};