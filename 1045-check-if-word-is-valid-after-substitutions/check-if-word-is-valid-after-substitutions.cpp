class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && s[i] == 'c')
            {
                string temp = "";
                int t = 2;
                while (!st.empty() && t--) {
                    temp.push_back(st.top());
                    st.pop();
                }
                if (temp == "ba") {
                   cout<<temp<<" ";
                    continue;
                } else {
                    st.push(temp[1]);
                    st.push(temp[0]);
                    st.push(s[i]);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};