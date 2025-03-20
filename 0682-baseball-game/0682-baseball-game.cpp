class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="C"){
                st.pop();
            }
            else if(operations[i]=="D"){
                int dEle=st.top();
                st.push(2*dEle);
            }
            else if(operations[i]=="+"){
                int dEle1=st.top();
                st.pop();
                int dEle2=st.top();
                st.push(dEle1);
                st.push(dEle1+dEle2);
            }
            //converting string to integer
            else{
                st.push(stoi(operations[i]));
            }
            
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};