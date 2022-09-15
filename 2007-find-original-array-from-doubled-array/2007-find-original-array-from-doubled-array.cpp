class Solution {
public:
    //T.C=O(nlogn) S.C=O(n)
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        //odd length return empty array(it must be doubled size)
        if(n%2==1) return {};
        //sort as the order does not matter
        sort(changed.begin(),changed.end());
        vector<int> ans;
        map<int,int> mp;//count the frequencies
        for(int i=0;i<n;i++)
            mp[changed[i]]++;
        for(int i=0;i<n;i++){
            //if element count becomes 0 go for next element checking
            if(mp[changed[i]]==0) continue;
            //as array is sorted, this case is element exists but double element does not
            //so cannot make a pair so return empty array
            if(mp[changed[i]*2]==0) return {};
            ans.push_back(changed[i]);
            //decrement both count
            mp[changed[i]]--;
            mp[changed[i]*2]--;
        }
        return ans;
    }
};