class Solution {
public:
    //T.C=O(N*k^2)
    bool isPalindrome(string str,int s,int e){
        while(s<e){
            if(str[s++]!=str[e--]) return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n=words.size();
        vector<vector<int>> ans;
        unordered_map<string,int> mp;
        set<int> st;
        //insert all words with index into hashmap and their size into set
        for(int i=0;i<n;i++){
            mp[words[i]]=i;
            st.insert(words[i].size());
        }
        for(int i=0;i<n;i++){
            int len=words[i].size();
            //case 1: If str1 is empty, then for any string str2 is a palindrome can match => (str1 + str2), (str2+str1)
            if(len==1){
                if(mp.count("") && mp[""]!=i){
                    ans.push_back({i,mp[""]});
                    ans.push_back({mp[""],i});
                }
                continue;
            }
            
            string rev=words[i];
            reverse(rev.begin(),rev.end());
            //case 2:If str1/str2 is the reverse part of others, then => (str1 + str2), (str2 + str1)
            if(mp.count(rev) && mp[rev]!=i){
                ans.push_back({i,mp[rev]});
            }
            
            for(auto size:st){
                if(len==size) break;
                //case 3: Little Tricky!!
/*str1 => [0,.....,x,.....n], where 0,.,x,n -> denotes index of string str1

Suppose, str1[0...x] is palindrome, then reverse(str2) must match with str1[x+1...n], output => (str2 + str1) 

For eg: 
str1 = "abacd", str2 = "cd", then palindrome => rev(str2) + str1 => dcabacd
[Note: Here, aba in str1 -> palindrome]*/
                if(isPalindrome(rev,0,len-1-size)){
                    string str1=rev.substr(len-size);
                    if(mp.count(str1)){
                        ans.push_back({i,mp[str1]});
                    }
                }
                
                //case 4: Similar to case 3,

/*If, str[x....n] is palindrome, then reverse(str2) must match with str1[0,...x], output => (str1 + str2)

For eg:
str1 = "abcbab", str2 = "abc", then palindrome => str1 + rev(str2) => abcbababc
[Note: Here, bab in str1 -> palindrome]*/
                if(isPalindrome(rev,size,len-1)){
                    string str2=rev.substr(0,size);
                    if(mp.count(str2)){
                        ans.push_back({mp[str2],i});
                    }
                }

            }
        }
        return ans;
    }
};