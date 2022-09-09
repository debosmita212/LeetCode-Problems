class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]!=b[0]) return a[0]>b[0];
        return a[1]<b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        //sort by attack in descending order
        sort(properties.begin(),properties.end(),comp);
        int maxi=INT_MIN;
        int ans=0;
        for(auto it:properties){
            if(maxi>it[1]) ans++; //if defense is small then weak attack and defense
            //so ans increases else update the maximum defense
            else maxi=it[1];
        }
        return ans;
    }
};