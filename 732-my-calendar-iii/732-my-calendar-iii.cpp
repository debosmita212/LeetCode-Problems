class MyCalendarThree {
public:
    int maxi=0;
    map<int,int> mp;//key:time; val:+1 if start,-1 if end
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int cnt=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            cnt+=it->second;
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */