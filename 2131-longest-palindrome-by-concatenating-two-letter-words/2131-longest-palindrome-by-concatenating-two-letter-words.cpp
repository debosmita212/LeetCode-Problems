class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count=0;
        //stores frequency of every word in map
        map<string,int> mp;
        for(auto it:words)
            mp[it]++;
        
        bool flag=false;
        for(auto it:words){
            string temp=it;
            reverse(temp.begin(),temp.end());
            //word and its reverse exist with their frequencies
            //decrease both frequency by 1 increase count by 4
            if(temp!=it && mp[it]>0 && mp[temp]>0){
                mp[temp]--;
                mp[it]--;
                count+=4;
            }
            //word and its reverse exist with their frequencies
            //word==reverse(word)
            //decrease frequency by 2 increase count by 4
            //bc*aa*aa*cb
            else if(temp==it && mp[it]>1){
                mp[it]-=2;
                count+=4;
            }
            //bc*gg*cb
            else if(temp==it && !flag && mp[it]>0){
                mp[it]--;
                count+=2;
                flag=true;
            }
        }
        return count;
    }
};