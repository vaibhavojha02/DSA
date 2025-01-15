class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>>dist(n,vector<long long>(n,INT_MAX));
        for(auto it : edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        for(int i =0;i<n;i++)dist[i][i] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
                }
            }
        }
        int maXCities = n+1;
        int city = -1;
        for(int i =0;i<n;i++){
            int count =0;
            for(int j =0;j<n;j++){
                if(dist[i][j] <= distanceThreshold){
                     count++;
                }
            }
            if(count<=maXCities){
                maXCities = count;
                city = i;
            }
        }
        return city;
    }
};