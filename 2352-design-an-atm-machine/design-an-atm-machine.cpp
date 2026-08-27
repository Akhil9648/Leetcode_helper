class ATM {
public:
    vector<int>curr;
    vector<int>val={20,50,100,200,500};
    ATM() {
        curr.resize(5,0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<5;i++){
            curr[i]+=banknotesCount[i];
        }
    }
    vector<int> withdraw(int amount) {
        vector<int>ans(5,0);
        for(int i=4;i>=0;i--){
            if(amount>=val[i]){
                int a=min(amount/val[i],curr[i]);
                ans[i]+=a;
                amount-=(a*val[i]);
            }
        }
        if(amount!=0) return {-1};
        for(int i=0;i<5;i++){
            curr[i]-=ans[i];
        }
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */