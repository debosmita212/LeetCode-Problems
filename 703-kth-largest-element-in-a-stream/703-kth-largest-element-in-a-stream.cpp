class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;//minHeap
    int cnt;
    KthLargest(int k, vector<int>& nums) {
        cnt=k;
        for(int i=0;i<nums.size();i++)
            pq.push(nums[i]);
        //so that it contains only k maximum elements
        while(pq.size()>cnt)
            pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        //after pushing make sure to keep only k maximum elements
        while(pq.size()>cnt)
            pq.pop();
        //return top
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */