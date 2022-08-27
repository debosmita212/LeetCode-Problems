class Solution {
public:
    int findMax(vector<int> &arr,int k){
        int n=arr.size();
        int maxi=INT_MIN;
        int curr=0; //stores cumulative sum
        set<int> s; //stores pefix sum of array
        s.insert(0); // put 0 into set, if curr_sum == k, (curr_sum - k) will be zero 
        for(int i=0;i<n;i++){
            curr+=arr[i];
            // find the prefix sum in set having sum == curr_sum - k
            auto it=s.lower_bound(curr-k);
             //if prefix sum is present, update the maxi
            if(it!=s.end()){
                maxi=max(maxi,curr-*it);
            }
            // insert prefix sum into set
            s.insert(curr);
        }
        return maxi;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),m=matrix[0].size();
        int maxi=INT_MIN;
        
        //Fix the position of two rows and take the cumulative sum of columns
        //between two fixed rows
        for(int start_row=0;start_row<n;start_row++){
            vector<int> col_arr(m,0);
            for(int end_row=start_row;end_row<n;end_row++){
                //take cumulative sum of columns between two fixed rows
                for(int col=0;col<m;col++){
                    col_arr[col]+=matrix[end_row][col];
                }
                //maximum subarray having sum less than equal to k
                int curr=findMax(col_arr,k);
                maxi=max(maxi,curr);
            }
        }
        return maxi;
    }
};