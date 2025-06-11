class Solution {
public:
    void precomputePrefixSum(vector<int>& prefixSumA,vector<int>& prefixSumB,const string& s,const int& n ,const int& a,const int& b){
        prefixSumA[0]=prefixSumB[0]=0;

        for(int i=0;i<n;i++){
            if(s[i]-'0'==a) prefixSumA[i+1]=1+prefixSumA[i];
            else prefixSumA[i+1]=prefixSumA[i];

            if(s[i]-'0'==b) prefixSumB[i+1]=1+prefixSumB[i];
            else prefixSumB[i+1]=prefixSumB[i];
        }
    }
    int calculateDiff(const string& s,const int& k,const int& a,const int&b){
        int n=s.size();
        vector<int> prefixSumA(n+1),prefixSumB(n+1);
        precomputePrefixSum(prefixSumA,prefixSumB,s,n,a,b);
        
        vector<int> minVal(4,INT_MAX);
        vector<int> minIdx(4,-1);
        minVal[0]=minIdx[0]=0;

        int maxDiff=INT_MIN;
        for(int end=k;end<=n;end++){
            int parA=prefixSumA[end]&1;
            int parB=prefixSumB[end]&1;
            int parity= ((parA^1)<<1)+parB;

            if(minVal[parity]!=INT_MAX){
                if(prefixSumB[minIdx[parity]]!=prefixSumB[end]){
                    maxDiff=max(maxDiff,(prefixSumA[end]-prefixSumB[end])-minVal[parity]);
                }
            }
            int start=end-k+1;
            parA=prefixSumA[start]&1;
            parB=prefixSumB[start]&1;
            parity=(parA<<1) + parB;
            int startDiff = prefixSumA[start] - prefixSumB[start];

            if(startDiff < minVal[parity]){
                minVal[parity]=startDiff;
                minIdx[parity]=start;
            }
        }
        return maxDiff;
        
    }
    int maxDifference(string s, int k) {
        int n=s.size();
        int maxDiff = INT_MIN;

        for(int a=0;a<=4;a++){
            for(int b=0;b<=4;b++){
                if(a==b) continue;
                int diff=calculateDiff(s,k,a,b);
                maxDiff=max(maxDiff,diff);
            }
        }

        return maxDiff;
    }
};