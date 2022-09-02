class MedianFinder {
public:
    priority_queue<int> left; //max-heap
    priority_queue<int,vector<int>,greater<int>> right; //min heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!left.empty() && num<left.top()){
            left.push(num);
            //to balance both transfer elements to right
            if(left.size()>right.size()+1){
                right.push(left.top());
                left.pop();
            }
            return;
        }
        right.push(num);
        //to balance both transfer elements to left
        if(right.size()>left.size()+1){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size()==right.size()){
            return (double)(left.top()+right.top())/2;
        }
        if(left.size()>right.size()) return left.top();
        return right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */