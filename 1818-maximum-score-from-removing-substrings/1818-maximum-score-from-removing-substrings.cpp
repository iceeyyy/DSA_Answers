class Solution {
public:
    string remove(string s,string substring){
        stack<char>st;

        for(int i=0;i<s.length();i++){
            if(s[i]==substring[1] && !st.empty() && st.top()==substring[0]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string ans="";

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        int ans=0;
        string maxstr = (x>y)?"ab":"ba";
        string minstr = (x>y)?"ba":"ab";
        int n=s.length();

        string first=remove(s,maxstr); //removing the subs with more point first
        int l=first.length();
        int charRemoved=n-l;
        ans+=(charRemoved)/2*max(x,y);

        string last=remove(first,minstr); //removing the substrin with less points
        int l1=last.length();
        int charRemoved1=l-l1;
        ans+=(charRemoved1)/2*min(x,y);

        return ans;

    }
};