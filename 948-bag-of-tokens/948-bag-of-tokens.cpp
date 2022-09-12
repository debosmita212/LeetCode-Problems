class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        //sort the tokens to apply two pointer
        sort(tokens.begin(),tokens.end());
        int l=0,r=tokens.size()-1;
        int cur_score=0,maxi=0;
        while(l<=r){
            if(tokens[l]<=power){ //face-up
                power-=tokens[l];
                l++;
                cur_score++;
                maxi=max(maxi,cur_score);
            }
            else if(cur_score>=1){ //face-down
                power+=tokens[r];
                r--;
                cur_score--;
                maxi=max(maxi,cur_score);
            }
            else{
                break; //not having enough power or enough score
            }
        }
        return maxi;
    }
};