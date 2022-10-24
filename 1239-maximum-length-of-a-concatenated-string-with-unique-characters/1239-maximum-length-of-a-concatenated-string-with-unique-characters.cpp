class Solution {
public:
    //DFS Solution
    int maxLength(vector<string>& arr,string str="",int index=0) {
        //Use set to check if the string contains all unique characters
        unordered_set<char> s(str.begin(),str.end());
        //as unique characters are equal to string size if all characters are unique
        if(s.size()!=((int)str.length())) return 0;
        
        int ret=str.length();
        for(int i=index;i<arr.size();i++){
            ret=max(ret,maxLength(arr,str+arr[i],i+1));
        }
        return ret;
    }
};