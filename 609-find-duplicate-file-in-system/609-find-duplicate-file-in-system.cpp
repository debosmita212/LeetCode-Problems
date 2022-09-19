class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        //store content,directory+filename in map
        unordered_map<string,vector<string>> mp;
        //scan the paths and store this
        for(auto path:paths){
            stringstream ss(path);
            string dir;
            string file;
            getline(ss,dir,' ');//root/a
            while(getline(ss,file,' ')){
                string content=file.substr(file.find('(')+1,file.find(')')-file.find('(')-1);//abcd
                string name=dir+'/'+file.substr(0,file.find('('));//root/a/2.txt
                mp[content].push_back(name);//abcd->[root/a/2.txt]
            }
        }
        vector<vector<string>> ans;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second.size()>1){ //repeats
                ans.push_back(it->second);
            }
        }
        return ans;
    }
};