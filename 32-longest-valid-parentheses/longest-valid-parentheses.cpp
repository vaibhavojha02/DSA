class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int>track(n,0);
        stack<pair<int,int>>st;
        for(int i = 0 ; i<n ; i++){
          if (!st.empty() && ((st.top().first == '(' && s[i] == ')') ||
                                (st.top().first == '[' && s[i] == ']') ||
                                (st.top().first == '{' && s[i] == '}'))) {
                        track[st.top().second] = 1;
                        track[i] = 1;
                        st.pop();
            }
            else{
                st.push({s[i],i});
            }  
        }
        int count = 0;
        int maxans = 0;
        for(int i  = 0;i<track.size();i++){
            cout<<track[i]<<" ";
           if(track[i]==1){
              count++;
           }
           else{
             maxans = max(maxans,count);
             count = 0;
           }
        }
         maxans = max(maxans,count);
        return maxans;
    }
};