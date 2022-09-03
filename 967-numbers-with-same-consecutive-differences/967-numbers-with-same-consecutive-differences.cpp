class Solution {
public:
    string str=""; //to store current number
    vector<int> ans; //to store the number
    void solve(int n,int k){
        //base case
        if(n==0){
            ans.push_back(stoi(str)); //pushing the number
            return;
        }
        //finding last digit in current number |a-b|==k
        int curr=str.back()-'0';
        if(curr+k<10){
            char temp='0'+curr+k;//taking next digit
            str+=temp;//updating current number
            solve(n-1,k); //call for next digit
            str.pop_back();
        }
        //finding last digit |b-a|==k
        if(k!=0 && curr-k>=0){
            char temp='0'+curr-k;
            str+=temp;
            solve(n-1,k);
            str.pop_back();
        }
        return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        if(n==0) return {};
        for(int i=1;i<10;i++){
            str=to_string(i);
            solve(n-1,k);
        }
        return ans;
    }
};