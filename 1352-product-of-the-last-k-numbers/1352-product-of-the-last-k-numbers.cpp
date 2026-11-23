class ProductOfNumbers {
public:
    vector<int> cont;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        cont.push_back(num);
    }
    
    int getProduct(int k) {
        int sum=1;
        int n=cont.size();
        for(int i=n-1;i>=n-k;i--){
            sum*=cont[i];
        }
        return sum;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */