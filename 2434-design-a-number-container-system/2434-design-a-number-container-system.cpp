class NumberContainers {
public:
        unordered_map<int,int> ind_nu;
        unordered_map<int,set<int>>nu_ind;
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if(ind_nu.count(index)){
            nu_ind[ind_nu[index]].erase(index);
            if(nu_ind[ind_nu[index]].size()==0){
                nu_ind.erase(ind_nu[index]);
            }
        }
        ind_nu[index]=number;
        nu_ind[number].insert(index);
    }
    
    int find(int number) {
        if(!nu_ind.count(number)) return -1;
        return *(nu_ind[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */