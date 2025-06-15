class Solution {
public:
    int maxDiff(int num) {
        string s=to_string(num);
        string maxVal=s;

        for(auto ch:s){
            if(ch!='9'){
                for(auto& c:maxVal){
                    if(c==ch) c='9';
                }
                break;
            }
        }
        string minVal=s;

        if(s[0]!='1'){ //if first digit isn't one
            char ch=s[0];
            for(auto& c:minVal){
                if(c==ch) c='1';
            }
        }
        else{
            for(int i=1;i<s.length();i++){
                //if 1st digit is 1 and the next digit is not 0 or 1
                if(s[i]!='0'&& s[i]!='1'){
                    char ch=s[i];
                    for(auto& c:minVal){
                        if(c==ch) c='0';
                    }
                    break;
                }
            }
        }
        int maxx=stoi(maxVal);
        int minn=stoi(minVal);

        return maxx-minn;
    }
};