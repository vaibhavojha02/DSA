class Solution {
public:
    unordered_map<int,vector<int>>mp;
    long long solve(int parent,int node,vector<int>&values){
        if(mp[node].size()==1 && mp[node][0]==parent){
            return values[node];
        }
        long long sum = 0;
        for(auto it :  mp[node]){
            if(it==parent)continue;
            sum += solve(node,it,values);
        }
        return min(sum,values[node]*1LL);
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values)
    {  
        mp.clear();
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        long long sum = 0;
        for(int i =0;i<values.size();i++){
            sum += values[i];
        }
        long long mini = solve(-1,0,values);
        return sum - mini;

    }
};