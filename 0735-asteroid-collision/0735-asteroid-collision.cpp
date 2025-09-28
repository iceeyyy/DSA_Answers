class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();

        for(int i=0;i<n;i++){
            bool flag=0;

            while(!st.empty() && asteroids[i]<0 && st.top()>0 ){
                if( abs(st.top()) < abs(asteroids[i]) ){
                    st.pop();
                    continue;
                }
                else if(abs(st.top()==abs(asteroids[i]))){
                    st.pop(); // both explode
                }
                flag=1;
                break;
            }
            if(!flag){
                st.push(asteroids[i]);
            }
        }

        vector<int> ans;

        while(!st.empty()){
            int element=st.top();
            st.pop();
            ans.push_back(element);
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};