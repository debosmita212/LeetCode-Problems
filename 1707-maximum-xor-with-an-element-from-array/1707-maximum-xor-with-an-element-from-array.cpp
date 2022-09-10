//T.C=(Q*32+N*32)
struct Node{
    Node* links[2];
    
    bool containsKey(int index){
        return (links[index]!=NULL);
    }
    void put(int index,Node* node){
        links[index]=node;
    }
    Node* get(int index){
        return links[index];
    }
};
class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root=new Node();
        }
        void insert(int num){
            Node* node=root;
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1;
                if(!node->containsKey(bit)){
                    node->put(bit,new Node());
                }
                node=node->get(bit);
            }
        }
        int findMax(int num){
            Node* node= root;
            int maxi=0;
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1;
                if(node->containsKey(!bit)){
                    maxi=maxi|(1<<i);
                    node=node->get(!bit);
                }
                else{
                    node=node->get(bit);
                }
            }
            return maxi;
        }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        //Sort the array
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> oQ;
        int q=queries.size();
        //Insert queries into data structure along with indexes
        for(int i=0;i<q;i++){
            oQ.push_back({queries[i][1],{queries[i][0],i}});
        }
        //Sort according to mi
        sort(oQ.begin(),oQ.end());
        int n=nums.size();
        Trie trie;
        int index=0;
        vector<int> ans(q,0);
        for(int i=0;i<q;i++){
            int mi=oQ[i].first;
            int xi=oQ[i].second.first;
            int qInd=oQ[i].second.second;
            //insert only those elements which are less than mi
            while(index<n && nums[index]<=mi){
                trie.insert(nums[index]);
                index++;
            }
            if(index==0)
                ans[qInd]=-1;
            else
                ans[qInd]=trie.findMax(xi);
        }
        return ans;
    }
};