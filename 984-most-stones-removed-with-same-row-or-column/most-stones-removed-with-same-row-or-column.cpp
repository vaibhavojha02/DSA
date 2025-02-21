class Solution {
public:
   void dfs(int idx,vector<vector<int>>& stones,vector<bool>&vis){
     vis[idx] = true;
     for(int i =0;i<stones.size();i++){
        int r = stones[idx][0];
        int c = stones[idx][1];
        if(vis[i]==false && ( stones[i][0]==r || stones[i][1]==c)){
            dfs(i,stones,vis);
        }
     }
   }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int groups = 0;
        vector<bool>vis(n,false);
        for(int i =0;i<n;i++){
            if(vis[i]==true)continue;
            else{
               dfs(i,stones,vis);
               groups++;
            }
        }
        return n-groups;
    }
};