class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int min_cost = 0;
        stack<pair<char,int>>st;
        for(int i =0;i<colors.size();i++){
            if(!st.empty() && st.top().first == colors[i])
            {
                if(neededTime[i] < st.top().second){
                    min_cost += neededTime[i];
                }
                else{
                    min_cost += st.top().second;
                    st.pop();
                    st.push({colors[i],neededTime[i]});
                }
            }
            else{
                st.push({colors[i],neededTime[i]});
            }
        }
        return min_cost;
    }
};