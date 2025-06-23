class Solution {
public:
    string converttoBaseK(long long num,int k){
        if(num==0) return "0";

        string res="";

        while(num>0){
            res+=to_string(num%k);
            num/=k;
        }
        return res;
    }
    bool isPalin(string s){
        int l=0;
        int r=s.length()-1;

        while(l<r){
            if(s[l]!=s[r]){
                return 0;
            }
            l++;
            r--;
        }
        return 1;
    }
    long long kMirror(int k, int n) {
        long long sum=0;
        int len=1;

        while(n>0){
            int half_length=(len+1)/2;

            long long min_num=pow(10,half_length-1);
            long long max_num=pow(10,half_length)-1;

            for(int num=min_num;num<=max_num;num++){
                string first_half=to_string(num);
                string second_half=first_half;

                reverse(second_half.begin(),second_half.end());

                string pal="";
                if( len & 1){
                    pal=first_half+second_half.substr(1); //addin the reverse of first_half instead of 1st digit
                    
                }
                else{
                    pal=first_half+second_half;
                }
                long long pal_num=stoll(pal);
                string base_k = converttoBaseK(pal_num,k);

                if(isPalin(base_k)){
                    sum+=pal_num;
                    n--;
                    if(n==0){
                        break;
                    }
                }
            }
            len++;
        }
        return sum;
    }
};