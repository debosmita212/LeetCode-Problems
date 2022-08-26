class Solution {
public:
    // the idea is to sort `n` and compare all sorted power of two
    // if they are matched, then it means they can be reordered to each other
    string sortStr(int n){
        //convert it to string and then sort
        string str=to_string(n);
        sort(str.begin(),str.end());
        return str;
    }
    bool reorderedPowerOf2(int n) {
        //sort n
        string str=sortStr(n);
        for(int i=0;i<31;i++){
            //we sort each power of 2 string (power of 2=1<<i)
            string s=sortStr(1<<i);
            //if both sorted string are equal then return true
            if(s==str) return true;
        }
        //not possible to reorder
        return false;
    }
};