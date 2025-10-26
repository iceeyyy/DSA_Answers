class Bank {
ArrayList<Long> val = new ArrayList<>();
    public Bank(long[] balance) {
        for(long b:balance){
            val.add(b);
        }
    }
    public boolean isValid(int account){
        return account>=1 && account<=val.size();
    }
    public boolean transfer(int account1, int account2, long money) {
        if(!isValid(account1) || !isValid(account2)) return false;
        if(val.get(account1-1)>=money){
            val.set(account1 - 1, val.get(account1 - 1) - money);
            val.set(account2 - 1, val.get(account2 - 1) + money); //can't use val.get(account-1)+=money because it returns an object and not a reference variable
            return true;
        }
        return false;
    }
    
    public boolean deposit(int account, long money) {
        if(!isValid(account)) return false;
        val.set(account-1,val.get(account-1) + money); //1-based index in terms of account numbering
        return true;
     }
    
    public boolean withdraw(int account, long money) {
        if(!isValid(account)) return false;
        if(val.get(account-1)>=money){
            val.set(account-1,val.get(account-1) - money);
            return true;
        }
        return false;
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * Bank obj = new Bank(balance);
 * boolean param_1 = obj.transfer(account1,account2,money);
 * boolean param_2 = obj.deposit(account,money);
 * boolean param_3 = obj.withdraw(account,money);
 */