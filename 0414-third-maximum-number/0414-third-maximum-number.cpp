class Solution {
public:
    //T.C=O(n) S.C=O(1)
    /*
    f=2
    s=1
    t=LONG_MIN
    */
    int thirdMax(vector<int>& nums) {
        long f=LONG_MIN,s=LONG_MIN,t=LONG_MIN;
        for(int it:nums){
            if(it==f || it==s || it==t) continue;
            if(it>f){
                t=s;      
                s=f;
                f=it;
            }
            else if(it>s){
                t=s;
                s=it;
            }
            else if(it>t){
                t=it;
            }
        }
        if(t!=LONG_MIN) return (int)t;
        else if(f!=LONG_MIN) return (int)f; //as if 3 elements not exists return the maximum
        else return (int)s;
    }
};