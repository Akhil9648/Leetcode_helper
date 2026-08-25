class NumberContainers {
public:
    unordered_map<int,int>ind;
    unordered_map<int,set<int>>num;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(ind.count(index)){
            int n=ind[index];
            num[n].erase(index);
            if(num[n].empty()) num.erase(n);
            ind.erase(index);
        }
        num[number].insert(index);
        ind[index]=number;
    }
    
    int find(int number) {
        if(num.count(number)) return *num[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */