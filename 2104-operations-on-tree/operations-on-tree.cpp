class LockingTree {
public:
    vector<int>par;
    unordered_map<int,int>mp;
    vector<vector<int>>arr;
    LockingTree(vector<int>& parent) {
        for(auto it:parent){
            par.push_back(it);
        }
        int n=par.size();
        arr.resize(n);
        for(int i=1;i<n;i++){
            arr[par[i]].push_back(i);
        }
    }
    bool lock(int num, int user) {
        if(mp.count(num)) return false;
        mp[num]=user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(!mp.count(num)) return false;
        if(mp[num]==user){
            mp.erase(num);
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
       int i=num;
       if(mp.count(num)) return false;
       while(i!=-1){
            if(mp.count(i)) return false;
            i=par[i];
       }
       queue<int>q;
       q.push(num);
       int flag=0;
       while(!q.empty()){
           int i=q.front();
           q.pop();
           for(auto it:arr[i]){
                q.push(it);
                if(mp.count(it)){
                    mp.erase(it);
                    flag=1;
                }
           }
       }
       if(flag==1){
         mp[num]=user;
         return true;
       }
       return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */