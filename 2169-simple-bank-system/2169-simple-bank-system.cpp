class Bank {
public:
vector<long long> val;
    Bank(vector<long long>& balance) {
        val = balance;
    }
    bool isValid(int account){
       return (account>=1 && account<=val.size());
    }
    bool transfer(int account1, int account2, long long money) {
        if(!isValid(account1)|| !isValid(account2)) return false;

        if(val[account1-1]>=money){
            val[account2-1]+=money;//transfered to account2
            val[account1-1]-=money; //withdrawn from account1
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(!isValid(account)) return false;
        val[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!isValid(account)) return false;
        if(val[account-1]>=money){
            val[account-1]-=money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */