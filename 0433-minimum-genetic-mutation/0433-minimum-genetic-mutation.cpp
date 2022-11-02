class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        //set contains all valid mutations
        unordered_set<string> st(bank.begin(),bank.end());
        if(!st.count(end)) return -1;//not in set
        //BFS
        queue<string> q;
        q.push(start);
        int steps=0,s;
        string curr;
        vector<char> available={'A','C','G','T'};
        unordered_set<string> vis; //either previously encountered or not
        vis.insert(start);
        while(!q.empty()){
            s=q.size();
            while(s--){
                curr=q.front();
                q.pop();
                //reached end mutation
                if(curr==end) return steps;
                
                //check for 4 options for 8 times as length should be 8
                //at each index we check the possibility of mutation by replcaing it with A,C,G,T
                for(int i=0;i<8;i++){
                    char temp=curr[i];
                    //replacing characters
                    for(int j=0;j<4;j++){
                        curr[i]=available[j];
                        //present in st but not in visited
                        if(st.find(curr)!=st.end()){
                            if(vis.find(curr)==vis.end()){
                                //push into queue and vis
                                q.push(curr);
                                vis.insert(curr);
                            }
                        }
                    }
                    //replacing with original one
                    curr[i]=temp;
                }
            }
            steps++;
        }
        return -1;
    }
};