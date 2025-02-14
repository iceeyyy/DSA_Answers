class ProductOfNumbers {
public:
    vector<int> ss={1};
    int n;
    int last_zero;
    ProductOfNumbers() {
        n=1;
        last_zero=-1;
    }
    
    void add(int num) {
        if(num==0) last_zero=n;
        if(ss.back()==0){
            ss.push_back(num);
        } 
        else{
            ss.push_back(ss.back()*num);
        }
        n++;
    }
    
    int getProduct(int k) {
        if(last_zero>= n-k) return 0;
        if(ss[n-k-1]==0) return ss[n-1];
        else{
            return ss[n-1]/ss[n-k-1];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */