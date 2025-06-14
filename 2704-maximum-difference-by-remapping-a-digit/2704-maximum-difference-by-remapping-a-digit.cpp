class Solution {
public:
    int minMaxDifference(int num) {
        string number=to_string(num);
        string maxStr=number;
        //making biggest number possible
        for(auto c:number){
            if(c!='9'){
                for(auto& ch:maxStr){
                    if(ch==c) ch='9';
                }
                break;
            }
        }

        string minStr=number;
        //making smallest string possible
        for(auto c:number){
            if(c!='0'){
                for(auto& ch:minStr){
                    if(ch==c) ch='0';
                }
                break;
            }
        }

        int sm=stoi(minStr);
        int lg=stoi(maxStr);

        return lg-sm;

        
    }
};