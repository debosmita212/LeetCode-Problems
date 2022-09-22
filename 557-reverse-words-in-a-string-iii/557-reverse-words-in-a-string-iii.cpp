class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                reverse(temp.begin(),temp.end());
                ans+=temp+' ';
                temp="";
                continue;
            }
            else if(i==s.length()-1){
                temp+=s[i];
                reverse(temp.begin(),temp.end());
                ans+=temp;
                break;
            }
            else{
                temp+=s[i];
            }
        }
        return ans;
    }
};