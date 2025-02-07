class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int i){
        if(i==parent[i]){
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    void unionDSU(int x,int y)
    {
         int x_parent =  find(x);
         int y_parent =  find(y);
         if(x_parent==y_parent)return;
         if(rank[x_parent]>rank[y_parent]){
            parent[y_parent] = x_parent;
         }
         else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent] = y_parent;
         }
         else{
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
         }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        for(auto &i : edges){
            int x = i[0];
            int y = i[1];
            unionDSU(x,y);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int abba = find(i);
            mp[abba]++;
        }
        long long result =0;
        long long  remaining = n;
        for(auto &i : mp){
            int size = i.second;
            result += (size*(remaining-size));
            remaining -= size;
        }
        return result;



    }
};