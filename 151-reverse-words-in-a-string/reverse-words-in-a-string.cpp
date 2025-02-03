class Solution {
public:
    string reverseWords(string s) {
       int start = 0;
       stack<string>st;
       while(start<s.size()){
        if(s[start]!=' '){
            int end = start;
            while(end<s.size() && s[end]!=' '){
                end++;
            }
            string temp = s.substr(start,end-start);
            st.push(temp);
            start = end;
            cout<<st.top()<<",";
            start = end;
        }
        start++;
      }
      string ans = "";
      while(!st.empty()){
         ans += st.top();
         st.pop();
         if(!st.empty()){
            ans += " ";
         }
        }

      return ans;
    }
};