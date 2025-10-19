class Solution {
public:
    void rotate(string&s,int b){
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.begin()+b);
        reverse(s.begin()+b,s.end());
    }
    string findLexSmallestString(string s, int a, int b) {
        string smallest=s;

        queue<string> q;
        unordered_set<string> st;

        q.push(s);
        st.insert(s);

        while(!q.empty()){
            string cur=q.front();
            q.pop();

            if(cur<smallest){
                smallest=cur;
            }
            //add a 
            string temp=cur;
            for(int i=1;i<temp.length();i+=2){
                temp[i]=((temp[i]-'0'+ a )%10)+'0';
            }

            if(!st.count(temp)){
                q.push(temp);
                st.insert(temp);
            }
            //rotate
            rotate(temp,b);
            if(!st.count(temp)){
                q.push(temp);
                st.insert(temp);
            }
        }
        
        return smallest;
    }
};